//
// Created by karl on 14.05.19.
//

#include "WbDeviceGetter.h"
#include <webots/robot.h>

WbDeviceTag WbDeviceGetter::getByName(const std::string& name) {
    return wb_robot_get_device(name.c_str());
}
