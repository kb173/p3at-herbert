//
// Created by karl on 13.05.19.
//

#include "Sensor.h"

double Sensor::getValue() {
    return value;
}

bool Sensor::setValue(double val) {
    value = val;

    return true; // TODO: When to return false?
}
