//
// Created by Max on 14.05.2019.
//

#ifndef P3AT_HERBERT_VIRTUALSENSORCONTROLLER_H
#define P3AT_HERBERT_VIRTUALSENSORCONTROLLER_H

#include "../Interfaces/IVirtualSensorController.h"
#include "../Interfaces/ISensor.h"
#include "../Devices/Sensor.h"
#include "controller/c/webots/remote_control.h"
#include <webots/types.h>
#include <memory>
#include <map>

class VirtualSensorController : public IVirtualSensorController {
public:
    VirtualSensorController(std::shared_ptr<IVirtualDeviceManager> dm) : IVirtualSensorController(dm) {};

    void setAllSensorValues() override;

};


#endif //P3AT_HERBERT_VIRTUALSENSORCONTROLLER_H
