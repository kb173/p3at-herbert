//
// Created by irena.ankerl on 30.04.2019.
//

#ifndef P3AT_HERBERT_IVIRTUALSENSORCONTROLLER_H
#define P3AT_HERBERT_IVIRTUALSENSORCONTROLLER_H

#include "controller/c/webots/types.h"

class IVirtualSensorController {
public:
    ///returns the last value measured by the specified distance sensor.
    virtual void wbr_distance_sensor_set_value(WbDeviceTag tag, double value) = 0;
};


#endif //P3AT_HERBERT_IVIRTUALSENSORCONTROLLER_H
