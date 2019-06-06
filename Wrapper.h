//
// Created by karl on 28.05.19.
//

#ifndef P3AT_HERBERT_WRAPPER_H
#define P3AT_HERBERT_WRAPPER_H


#include <memory>
#include "Interfaces/IRealDeviceController.h"

class Wrapper {
public:
    static void setController(std::shared_ptr<IRealDeviceController> controller);

    static bool start(void *arg);

    static void stop();

    static bool hasFailed();

    static void stopActuators();

    static int robotStep(int period);

    static const std::shared_ptr<IRealDeviceController> &getController();

protected:
    static std::shared_ptr<IRealDeviceController> controller;
};


#endif //P3AT_HERBERT_WRAPPER_H
