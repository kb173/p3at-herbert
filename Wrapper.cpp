#include <utility>

#include <utility>

#include <utility>

//
// Created by karl on 28.05.19.
//

#include "Wrapper.h"

// Initialize static variables
std::shared_ptr<IRealDeviceController> Wrapper::realDeviceController = nullptr;
std::shared_ptr<IVirtualSensorController> Wrapper::virtualSensorController = nullptr;
std::shared_ptr<IVirtualMotorController> Wrapper::virtualMotorController = nullptr;

bool Wrapper::start(void *arg) {
    return realDeviceController->start(arg);
}

void Wrapper::stop() {
    realDeviceController->stop();
}

bool Wrapper::hasFailed() {
    return realDeviceController->hasFailed();
}

void Wrapper::stopActuators() {
    realDeviceController->stopActuators();
}

int Wrapper::robotStep(int period) {
    // TODO: Calculate time here?
    realDeviceController->robotStep(0);
    virtualSensorController->setAllSensorValues();

    return 0; // FIXME
}

void Wrapper::setRealDeviceController(std::shared_ptr<IRealDeviceController> newController) {
    realDeviceController = std::move(newController);
}

void Wrapper::setVirtualSensorController(std::shared_ptr<IVirtualSensorController> newController) {
    virtualSensorController = std::move(newController);
}

void Wrapper::setVirtualMotorController(std::shared_ptr<IVirtualMotorController> newController) {
    virtualMotorController = std::move(newController);
}

void Wrapper::motorSetVelocity(WbDeviceTag tag, double velocity) {
    virtualMotorController->wbr_motor_set_velocity(tag, velocity);
}
