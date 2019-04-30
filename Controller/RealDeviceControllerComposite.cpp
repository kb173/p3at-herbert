//
// Created by karl on 30.04.19.
//

#include "RealDeviceControllerComposite.h"

bool RealDeviceControllerComposite::start(void *arg) {
    bool success = false;

    for (const auto& controller : controllers) {
        // If any function fails, success turns and stays false
        success = success && controller->start(arg);
    }

    return success;
}

void RealDeviceControllerComposite::stop() {
    for (const auto& controller : controllers) {
        controller->stop();
    }
}

bool RealDeviceControllerComposite::hasFailed() {
    bool failed = false;

    for (const auto& controller : controllers) {
        // Failed stays true if it becomes true at any point
        failed = failed || controller->hasFailed();
    }

    return failed;
}

void RealDeviceControllerComposite::stopActuators() {
    for (const auto& controller : controllers) {
        controller->stopActuators();
    }
}

int RealDeviceControllerComposite::robotStep(int period) {
    // TODO: Calculate the time we took (endTime - startTime)
    int timeSum = 0;

    for (const auto& controller : controllers) {
        // 0 is passed for period because we're adding up the time and/or waiting here
        timeSum += controller->robotStep(0);
    }

    if (timeSum < period) {
        // If we took less time than the given period, we wait until that time is reached
        // TODO: Wait for the rest of the time
        return 0;
    } else {
        // If we took more time, the exceeded time is returned
        return timeSum - period;
    }
}
