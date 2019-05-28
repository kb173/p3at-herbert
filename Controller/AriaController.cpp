//
// Created by mathias on 30.04.19.
//

#include <sstream>
#include <iostream>
#include "AriaController.h"
#include "../Interfaces/IMotor.h"
#include "../Tools/Converter.h"
#include "../Devices/Sensor.h"

// TODO: Test driven development requires tests :-)

bool AriaController::start(void *arg) {
    Aria::init();
    connectionStopped = false;

    //std::string args((const char*)arg);

    ArArgumentBuilder ab = ArArgumentBuilder();
    ab.add((const char *) arg);

    argParser = std::make_shared<ArArgumentParser>(ArArgumentParser(&ab));
    argParser->loadDefaultArguments();

    robotConnector = std::make_shared<ArRobotConnector>(argParser.get(), &realRobot);
    sonarConnector = std::make_shared<ArSonarConnector>(argParser.get(), &realRobot, robotConnector.get());

    if (!robotConnector->connectRobot()) {
        ArLog::log(ArLog::Normal, "Could not connect to realRobot");

        if (argParser->checkHelpAndWarnUnparsed()) {
            Aria::logOptions();
            Aria::exit(1);

            connectionStopped = true;
            return false;
        }
    }

    if (!Aria::parseArgs()) {
        Aria::logOptions();
        Aria::exit(2);

        connectionStopped = true;
        return false;
    }

    realRobot.addRangeDevice(&sonarInitializer);
    realRobot.addRangeDevice(&sonarInitializer2);

    // TODO: Check if this is really needed?
    if(!sonarConnector->connectSonars()) {
        ArLog::log(ArLog::Normal, "Could not connect to sonar sensors");
        Aria::logOptions();
        Aria::exit(3);

        connectionStopped = false;
        return false;
    }

    // Allow some time to read laser data
    ArUtil::sleep(500);

    // Start the realRobot processing cycle running in the background.
    // True parameter means that if the connection is lost, then the
    // run loop ends.
    realRobot.enableMotors();
    realRobot.enableSonar();

    realRobot.runAsync(true);

    realSonar = std::shared_ptr<ArRangeDevice>(realRobot.findRangeDevice("sonar"));

    return 0;
}

void AriaController::stop() {
    ArLog::log(ArLog::Normal, "Ending realRobot thread...");
    realRobot.stopRunning();
    connectionStopped = true;

    // wait for the thread to stop
    realRobot.waitForRunExit();

    ArLog::log(ArLog::Normal, "Exiting.");
    Aria::exit();
}

bool AriaController::hasFailed() {
    return connectionStopped;
}

// TODO: Find out what happens when we resume

void AriaController::stopActuators() {
    //realRobot.setVel(0);
    //realRobot.set

    // might well be that stop doesnt show the wanted results.
    // if it doesn't we should set the velocity and possible other properties to zero
    realRobot.stop();
}

// TODO: gets the values from our virtual p3at struct and sets the values for the actuators and gets them from the sensors

int AriaController::robotStep(int period) {
    time_t start = time(nullptr);
    double periodAsDouble = ((double) period) / 1000;

    Converter converter = Converter();
    std::string logMessage;

    auto leftWheelsPtr = virtualRobot->getLeftWheels();
    std::shared_ptr<IMotor> leftWheels = std::dynamic_pointer_cast<IMotor>(leftWheelsPtr);
    auto rightWheelsPtr = virtualRobot->getRightWheels();
    std::shared_ptr<IMotor> rightWheels = std::dynamic_pointer_cast<IMotor>(rightWheelsPtr);
    auto backSonarArrayPtr = virtualRobot->getBackSonarArray();
    auto frontSonarArrayPtr = virtualRobot->getFrontSonarArray();


    double velocityLeft = converter.radToMm(leftWheels->getVelocity(), virtualRobot->getRadius());
    double velocityRight = converter.radToMm(rightWheels->getVelocity(), virtualRobot->getRadius());

    realRobot.lock();
    if (realRobot.areMotorsEnabled()) {
        std::ostringstream oss, oss2;
        oss << velocityLeft;
        oss2 << velocityRight;
        logMessage = "Motors running line with velocity of " + oss.str() + "m/s on left wheel"
                                                                           "and velocity of " + oss2.str() +
                     "m/s on right wheel";
        ArLog::log(ArLog::Normal, logMessage.c_str());

        realRobot.setVel2(velocityLeft, velocityRight);
    } else {
        ArLog::log(ArLog::Normal, "Motors were not enabled");
    }

    if (realRobot.areSonarsEnabled()) {
        // In the order of right to left having frontal vision on the realRobot

        /*
         *  Sensors placement in the ARIA array
         *
         *       2  3   4  5
         *       ___________
         *    1 /           \ 6
         *      |           |
         *    0 |           | 7
         *      |           |
         *      |           |
         *      |           |
         *   15 |           | 8
         *      |   P3AT    |
         *   14 \___________/ 9
         *
         *     13  12   11  10
         */
        if (realSonar != nullptr) {
            auto virtualFrontSonarVector = virtualRobot->getFrontSonarArray();
            auto virtualBackSonarVector = virtualRobot->getBackSonarArray();

            for (int i = 0; i < 16; i++) {
                std::cout << realRobot.getSonarRange(i) << std::endl;
            }

            for (int i = 0; i < 8; i++) {
                std::dynamic_pointer_cast<ISensor>(virtualFrontSonarVector[i])->setValue(realRobot.getSonarRange(i));
            }

            for (int i = 8; i < 16; i++) {
                std::dynamic_pointer_cast<ISensor>(virtualBackSonarVector[i - 8])->setValue(realRobot.getSonarRange(i));
            }

            std::cout << std::endl;
        }

    } else {
        ArLog::log(ArLog::Normal, "Sonars were not enabled.");
    }
    realRobot.unlock();


    // We must "lock" the ArRobot object
    // before calling its methods, and "unlock" when done, to prevent conflicts
    // with the background thread started by the call to realRobot.runAsync().
    // Unlock the realRobot before executing the ArUtil::sleep(ms) command.

    std::ostringstream oss;
    oss << period;
    logMessage = "realRobot executing commands for " + oss.str() + " time";
    ArLog::log(ArLog::Normal, logMessage.c_str());
    ArUtil::sleep(period);

    // The realRobot should at least wait period seconds and return deltatime if exceeds
    // This should be necessary, because the realRobot itself runs on another thread
    double secondsSinceStart = difftime(time(nullptr), start);
    while (secondsSinceStart < period) {
        secondsSinceStart = difftime(time(nullptr), start);
    }
    int deltaTime = (int) (secondsSinceStart - periodAsDouble) * 1000;

    return deltaTime;
}

void AriaController::fillSonarDevices(std::vector<std::shared_ptr<IDevice>> &virtualSonarVector, double startAngle, int multiplier) {
    double currentAngle = startAngle;
    double angleSize = (double) 180 / virtualSonarVector.size();

    for (int i = 0; i < 8; i++) { // TODO: Hardcoded

        double range = realSonar->currentReadingPolar(currentAngle, currentAngle + angleSize * multiplier);
        auto currentSonar = std::make_shared<Sensor>();
        currentSonar->setValue(range);
        virtualSonarVector[i] = currentSonar;

        currentAngle += angleSize * multiplier;
    }
}

AriaController::AriaController(std::shared_ptr<IP3AT> virtualRobot) : virtualRobot(virtualRobot) {}



