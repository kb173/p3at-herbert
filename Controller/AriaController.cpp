//
// Created by mathias on 30.04.19.
//

#include <sstream>
#include "AriaController.h"
#include "../Interfaces/IMotor.h"

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
        Aria::exit(1);

        connectionStopped = true;
        return false;
    }

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
    time_t start = time(0);
    double periodAsDouble = ((double) period) / 1000;

    auto leftWheelsPtr = virtualRobot->getLeftWheels();
    std::shared_ptr<IMotor> leftWheels = std::dynamic_pointer_cast<IMotor>(leftWheelsPtr);
    auto rightWheelsPtr = virtualRobot->getRightWheels();
    std::shared_ptr<IMotor> rightWheels = std::dynamic_pointer_cast<IMotor>(rightWheelsPtr);
    auto backSonarArrayPtr = virtualRobot->getBackSonarArray();
    /*
    std::shared_ptr<ISensor> backSonarArray = std::dynamic_pointer_cast<ISensor>(backSonarArrayPtr);
    auto frontSonarArrayPtr = virtualRobot->getFrontSonarArray();
    std::shared_ptr<std::list<ISensor>> frontSonarArray = std::dynamic_pointer_cast<ISensor>(frontSonarArrayPtr);*/


    // TODO: check the transission from WeBots velocity to ARIA velocity
    double velocityLeft = leftWheels->getVelocity();
    double velocityRight = rightWheels->getVelocity();

    if (velocityLeft == velocityRight) {
        std::ostringstream oss;
        oss << velocityLeft;
        std::string logMessage = "Driving in a straight line with velocity of " + oss.str() + "m/s";
        ArLog::log(ArLog::Normal, logMessage.c_str());


        realRobot.setVel(velocityLeft);
    } else {

    }

    if (realRobot.areSonarsEnabled()) {
        std::map<int, ArSonarMTX *> *sonarArray = realRobot.getSonarMap();
    }

    double secondsSinceStart = difftime( time(0), start);


    // The robot should at least wait period seconds and return deltatime if exceeds
    while(secondsSinceStart < period) {
        secondsSinceStart = difftime(time(0), start);
    }

    int deltaTime = (int) (secondsSinceStart - periodAsDouble) * 1000;

    return deltaTime;
}

AriaController::AriaController(const std::shared_ptr<IP3AT> &virtualRobot) : virtualRobot(virtualRobot) {}

