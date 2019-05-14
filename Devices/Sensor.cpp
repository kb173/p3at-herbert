//
// Created by karl on 13.05.19.
//

#include "Sensor.h"

Sensor::Sensor() {
    value = 0;
}

double Sensor::getValue() {
    return value;
}

void Sensor::setValue(double val) {
    value = val;
}
