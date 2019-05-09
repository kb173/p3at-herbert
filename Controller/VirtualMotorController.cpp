//
// Created by karl on 09.05.19.
//

#include "VirtualMotorController.h"
#include "../Interfaces/IMotor.h"

void VirtualMotorController::wbr_motor_set_position(WbDeviceTag tag, double position) {

}

void VirtualMotorController::wbr_motor_set_acceleration(WbDeviceTag tag, double acceleration) {

}

void VirtualMotorController::wbr_motor_set_velocity(WbDeviceTag tag, double velocity) {
    std::shared_ptr<IDevice> device = deviceManager->getDeviceByTag(tag);
    std::shared_ptr<IMotor> motor;

    motor = std::dynamic_pointer_cast<IMotor>(device);

    if (motor != nullptr) {
        motor->setVelocity(velocity);
    }
}