//
// Created by karl on 28.05.19.
//

#include <webots/remote_control.h>
#include <iostream>
#include "Interfaces/IRealDeviceController.h"
#include "Controller/RealDeviceControllerComposite.h"
#include "Wrapper.h"
#include "Controller/AriaController.h"
#include "Manager/VirtualDeviceManager.h"
#include "Interfaces/IVirtualMotorController.h"
#include "Controller/VirtualMotorController.h"
#include "Robots/P3AT.h"
#include "Tools/WbDeviceGetter.h"
#include "entry_points.hpp"
#include "Controller/VirtualSensorController.h"

bool wbr_init(WbrInterface *ri) {
    std::cout << "wbr_init called..." << std::endl;

    auto deviceManager = std::dynamic_pointer_cast<IVirtualDeviceManager>
            (std::make_shared<VirtualDeviceManager>());
    auto motorController = std::dynamic_pointer_cast<IVirtualMotorController>
            (std::make_shared<VirtualMotorController>(deviceManager));
    auto virtualRobot = std::dynamic_pointer_cast<IP3AT>
            (std::make_shared<P3AT>(20));
    auto ariaController = std::dynamic_pointer_cast<IRealDeviceController>
            (std::make_shared<AriaController>(virtualRobot));
    auto deviceGetter = std::dynamic_pointer_cast<IWbDeviceGetter>
            (std::make_shared<WbDeviceGetter>(WbDeviceGetter()));

    virtualRobot->fillDeviceManager(deviceManager, deviceGetter);

    Wrapper::setRealDeviceController(ariaController);
    Wrapper::setVirtualSensorController(std::make_shared<VirtualSensorController>(deviceManager));
    Wrapper::setVirtualMotorController(motorController);

    std::cout << "Linking wrapper functions..." << std::endl;

    ri->mandatory.wbr_start = Wrapper::start;
    ri->mandatory.wbr_has_failed = Wrapper::hasFailed;
    ri->mandatory.wbr_robot_step = Wrapper::robotStep;
    ri->mandatory.wbr_stop = Wrapper::stop;
    ri->mandatory.wbr_stop_actuators = Wrapper::stopActuators;

    ri->wbr_motor_set_velocity = Wrapper::motorSetVelocity;

    std::cout << "Done" << std::endl;

    return true;
}

void wbr_cleanup() {
    std::cout << "wbr_cleanup called..." << std::endl;
}
