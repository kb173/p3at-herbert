//
// Created by karl on 28.05.19.
//

#ifndef P3AT_HERBERT_WRAPPER_H
#define P3AT_HERBERT_WRAPPER_H


#include <memory>
#include "Interfaces/IRealDeviceController.h"
#include "Interfaces/IVirtualSensorController.h"
#include "Interfaces/IVirtualMotorController.h"

class Wrapper {
public:
    static void setRealDeviceController(std::shared_ptr<IRealDeviceController> newController);

    static void setVirtualSensorController(std::shared_ptr<IVirtualSensorController> newController);

    static void setVirtualMotorController(std::shared_ptr<IVirtualMotorController> newController);

    static bool start(void *arg);

    static void stop();

    static bool hasFailed();

    static void stopActuators();

    static int robotStep(int period);

    static void motorSetVelocity(WbDeviceTag tag, double velocity);

protected:
    static std::shared_ptr<IRealDeviceController> realDeviceController;

    static std::shared_ptr<IVirtualSensorController> virtualSensorController;

    static std::shared_ptr<IVirtualMotorController> virtualMotorController;
};


#endif //P3AT_HERBERT_WRAPPER_H
