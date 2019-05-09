//
// Created by mathias on 30.04.19.
//

#ifndef P3AT_HERBERT_ARIACONTROLLER_H
#define P3AT_HERBERT_ARIACONTROLLER_H

#include <Aria.h>
#include "../Interfaces/IRealDeviceController.h"

/// Has functions to actually set and apply the data to and from the real robot, does this in the tick function
/// For examples look at: https://github.com/cinvesrob/Aria/blob/master/examples/
/// e.g. simpleMotionCommands.cpp

class AriaController : IRealDeviceController {
public:
    bool start(void *arg) override;

    void stop() override;

    bool hasFailed() override;

    void stopActuators() override;

    int robotStep(int period) override;

private:
    ArRobot realRobot;
    ArArgumentParser argParser;
    bool connectionStopped;


};


#endif //P3AT_HERBERT_ARIACONTROLLER_H
