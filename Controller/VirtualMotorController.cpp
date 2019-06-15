//
// Created by karl on 09.05.19.
//

#include "VirtualMotorController.h"
#include "../Interfaces/IMotor.h"

void VirtualMotorController::setPosition(WbDeviceTag tag, double position) {

}

void VirtualMotorController::setAcceleration(WbDeviceTag tag, double acceleration) {

}

void VirtualMotorController::setVelocity(WbDeviceTag tag, double velocity) {
    std::shared_ptr<IMotor> motor = std::dynamic_pointer_cast<IMotor>(deviceManager->getDeviceByTag(tag));

    if (motor != nullptr) {
        motor->setVelocity(velocity);
    }
}
