//
// Created by Max on 14.05.2019.
//

#include "VirtualSensorController.h"

void VirtualSensorController::setAllSensorValues() {

    for (auto device : deviceManager->getDevices()) {
        auto sensor = std::dynamic_pointer_cast<ISensor>(device.second);

        if (sensor) {
            //wbr_distance_sensor_set_value(device.first, sensor->getValue());
        }
    }

}