//
// Created by karl on 15.05.19.
//

#include "MockWbDeviceGetter.h"

WbDeviceTag MockWbDeviceGetter::getByName(const std::string &name) {
    if (name == "front left wheel") {
        return 1;
    } else if (name == "front right wheel") {
        return 2;
    } else if (name == "back left wheel") {
        return 3;
    } else if (name == "back right wheel") {
        return 4;
    } else if (name == "sensor0") {
        return 10;
    } else if (name == "sensor1") {
        return 11;
    } else if (name == "sensor2") {
        return 12;
    } else if (name == "sensor3") {
        return 13;
    } else if (name == "sensor4") {
        return 14;
    } else if (name == "sensor5") {
        return 15;
    } else if (name == "sensor6") {
        return 16;
    } else if (name == "sensor7") {
        return 17;
    } else if (name == "sensor8") {
        return 18;
    } else if (name == "sensor9") {
        return 19;
    } else if (name == "sensor10") {
        return 20;
    } else if (name == "sensor11") {
        return 21;
    } else if (name == "sensor12") {
        return 22;
    } else if (name == "sensor13") {
        return 23;
    } else if (name == "sensor14") {
        return 24;
    } else if (name == "sensor15") {
        return 25;
    }

    return 0;
}
