//
// Created by karl on 20.05.19.
//

#include <iostream>
#include "Controller/AriaController.h"
#include "Robots/P3AT.h"
#include "Controller/VirtualMotorController.h"
#include "Manager/VirtualDeviceManager.h"
#include "Tools/MockWbDeviceGetter.h"

int main () {
    std::cout << "Test" << std::endl;
    std::shared_ptr<P3AT> p3at = std::make_shared<P3AT>(210);
    std::shared_ptr<AriaController> ac = std::make_shared<AriaController>(p3at);
    std::shared_ptr<VirtualDeviceManager> vdm = std::make_shared<VirtualDeviceManager>();
    p3at->fillDeviceManager(vdm, std::make_shared<MockWbDeviceGetter>());
    std::shared_ptr<VirtualMotorController> vmc = std::make_shared<VirtualMotorController>(vdm);

    ac->start((void*)"-rp /dev/ttyUSB0");

    while (true) {
        std::dynamic_pointer_cast<IMotor>(p3at->getLeftWheels())->setVelocity(-0.3);
        std::dynamic_pointer_cast<IMotor>(p3at->getRightWheels())->setVelocity(0.3);
        ac->robotStep(1);
    }
}