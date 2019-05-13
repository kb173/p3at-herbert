//
// Created by karl on 13.05.19.
//

#ifndef P3AT_HERBERT_SENSOR_H
#define P3AT_HERBERT_SENSOR_H


#include "../Interfaces/ISensor.h"

class Sensor : public ISensor {
public:
    double getValue() override;

    bool setValue(double val) override;

private:
    double value{};

};


#endif //P3AT_HERBERT_SENSOR_H
