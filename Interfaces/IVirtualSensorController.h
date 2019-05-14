//
// Created by irena.ankerl on 30.04.2019.
//

#ifndef P3AT_HERBERT_IVIRTUALSENSORCONTROLLER_H
#define P3AT_HERBERT_IVIRTUALSENSORCONTROLLER_H

#include "controller/c/webots/types.h"
#include "IVirtualDeviceManager.h"

class IVirtualSensorController {
public:
    IVirtualSensorController(std::shared_ptr<IVirtualDeviceManager> dm) : deviceManager(std::move(dm)) {};

    ///sets all sensor values in webots
    virtual void setAllSensorValues() = 0;

    virtual ~IVirtualSensorController() = default;

protected:
    std::shared_ptr<IVirtualDeviceManager> deviceManager;
};


#endif //P3AT_HERBERT_IVIRTUALSENSORCONTROLLER_H
