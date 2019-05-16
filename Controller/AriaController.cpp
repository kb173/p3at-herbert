//
// Created by mathias on 30.04.19.
//

#include <sstream>
#include <iostream>
#include "AriaController.h"
#include "../Interfaces/IMotor.h"
#include "../Tools/Converter.h"

// TODO: implement empty functions
// TODO: Test driven development requires tests :-)

bool AriaController::start(void *arg) {
    Aria::init();
    connectionStopped = false;

    //std::string args((const char*)arg);
    ArArgumentBuilder ab = ArArgumentBuilder();
    ab.add((const char*)arg);

    *argParser = ArArgumentParser(&ab);
    argParser->loadDefaultArguments();

    ArRobotConnector robotConnector(argParser, &realRobot);
    ArSonarConnector sonarConnector(argParser, &realRobot, &robotConnector);

    if(!robotConnector.connectRobot()) {
        ArLog::log(ArLog::Normal, "Could not connect to robot");

        if(argParser->checkHelpAndWarnUnparsed()) {
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


    // TODO: Check if this is really needed?
    if(!sonarConnector.connectSonars()) {
        ArLog::log(ArLog::Normal, "Could not connect to sonar sensors");
        Aria::logOptions();
        Aria::exit(3);

        connectionStopped = false;
        return false;
    }

    // Allow some time to read laser data
    ArUtil::sleep(500);

    // Start the robot processing cycle running in the background.
    // True parameter means that if the connection is lost, then the
    // run loop ends.
    realRobot.runAsync(true);

    // We must "lock" the ArRobot object
    // before calling its methods, and "unlock" when done, to prevent conflicts
    // with the background thread started by the call to robot.runAsync() above.
    // Unlock the robot before executing the ArUtil::sleep(ms) command.
    realRobot.lock();

    return true;
}

void AriaController::stop() {
    ArLog::log(ArLog::Normal, "Ending robot thread...");
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

    realRobot.enableMotors();
    if(realRobot.areMotorsEnabled()) {
        std::ostringstream oss, oss2;
        oss << velocityLeft;
        oss2 << velocityRight;
        logMessage = "Motors running line with velocity of " + oss.str() + "m/s on left wheel"
                                                    "and velocity of " + oss2.str() + "m/s on right wheel";
        ArLog::log(ArLog::Normal, logMessage.c_str());

        realRobot.setVel2(velocityLeft, velocityRight);
    } else {
        ArLog::log(ArLog::Normal, "Motors were not enabled");
    }

    realRobot.enableSonar();
    if (realRobot.areSonarsEnabled()) {
        // In the order of right to left having frontal vision on the robot

        realSonar = realRobot.findRangeDevice("sonar");
        auto virtualFrontSonarVector = virtualRobot->getFrontSonarArray();
        auto virtualBackSonarVector = virtualRobot->getBackSonarArray();

        fillSonarDevices(virtualFrontSonarVector);
        fillSonarDevices(virtualBackSonarVector);

    } else {
        ArLog::log(ArLog::Normal, "Sonars were not enabled.");
    }

    // We must "lock" the ArRobot object
    // before calling its methods, and "unlock" when done, to prevent conflicts
    // with the background thread started by the call to robot.runAsync().
    // Unlock the robot before executing the ArUtil::sleep(ms) command.
    realRobot.unlock();
    std::ostringstream oss;
    oss << period;
    logMessage = "Robot executing commands for " + oss.str() + " time";
    ArLog::log(ArLog::Normal, logMessage.c_str());
    ArUtil::sleep(period);

    // The robot should at least wait period seconds and return deltatime if exceeds
    // This should be necessary, because the robot itself runs on another thread
    double secondsSinceStart = difftime(time(nullptr), start);
    while(secondsSinceStart < period) {
        secondsSinceStart = difftime(time(nullptr), start);
    }
    int deltaTime = (int) (secondsSinceStart - periodAsDouble) * 1000;

    realRobot.lock();

    return deltaTime;
}

void AriaController::fillSonarDevices(std::vector<std::shared_ptr<IDevice>> virtualSonarVector) {
    double currentAngle = 0;
    double angleSize = (double) 180 / virtualSonarVector.size();

    for(int i = 0; i < virtualSonarVector.size(); i++) {

        double range = realSonar->currentReadingPolar(currentAngle, currentAngle + angleSize);

        auto currentSonar = std::dynamic_pointer_cast<ISensor>(virtualSonarVector[i]);
        currentSonar->setValue(range);

        currentAngle += angleSize;
    }
}

AriaController::AriaController(const std::shared_ptr<IP3AT> &virtualRobot) : virtualRobot(virtualRobot) {}



