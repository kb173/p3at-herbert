//
// Created by irena.ankerl on 30.04.2019.
//

#ifndef P3AT_HERBERT_IVIRTUALSENSORCONTROLLER_H
#define P3AT_HERBERT_IVIRTUALSENSORCONTROLLER_H

#include <webots/types.h>
#include "IVirtualDeviceManager.h"

/// Implements the required WeBots remote control functions for sensors.
/// These functions should be mapped to the incoming WeBots calls.
class IVirtualSensorController {
public:
    explicit IVirtualSensorController(std::shared_ptr<IVirtualDeviceManager> dm) : deviceManager(std::move(dm)) {};

    /// sets all sensor values in webots
    virtual void setAllSensorValues() = 0;

    virtual ~IVirtualSensorController() = default;

protected:
    std::shared_ptr<IVirtualDeviceManager> deviceManager;
};


#endif //P3AT_HERBERT_IVIRTUALSENSORCONTROLLER_H
