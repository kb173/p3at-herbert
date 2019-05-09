//
// Created by mathias on 30.04.19.
//

#include "AriaController.h"
#include "Aria.h"

// TODO: implement empty functions
// TODO: Test driven development requires tests :-)

bool AriaController::start(void *arg) {
    Aria::init();
    connectionStopped = false;

    //std::string args((const char*)arg);
    ArArgumentBuilder ab = ArArgumentBuilder();
    ab.add((const char*)arg);

    argParser = ArArgumentParser(&ab);
    argParser.loadDefaultArguments();

    ArRobotConnector robotConnector(&argParser, &realRobot);

    if(!robotConnector.connectRobot()) {
        ArLog::log(ArLog::Normal, "Could not connect to robot");

        if(argParser.checkHelpAndWarnUnparsed()) {
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
    return 0;
}
