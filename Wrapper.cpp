#include <utility>
#include <iostream>

//
// Created by karl on 28.05.19.
//

#include "Wrapper.h"

// Initialize static variables
std::shared_ptr<IRealDeviceController> Wrapper::realDeviceController = nullptr;
std::shared_ptr<IVirtualSensorController> Wrapper::virtualSensorController = nullptr;
std::shared_ptr<IVirtualMotorController> Wrapper::virtualMotorController = nullptr;

bool Wrapper::start(void *arg) {
    std::cout << "Wrapper start" << std::endl;
    return realDeviceController->start(arg);
}

void Wrapper::stop() {
    std::cout << "Wrapper stop" << std::endl;
    realDeviceController->stop();
}

bool Wrapper::hasFailed() {
    std::cout << "Wrapper has failed?" << std::endl;
    return realDeviceController->hasFailed();
}

void Wrapper::stopActuators() {
    std::cout << "Wrapper stop actuators" << std::endl;
    realDeviceController->stopActuators();
}

int Wrapper::robotStep(int period) {
    std::cout << "Wrapper robot step" << std::endl;
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
    std::cout << "Wrapper motor set velocity " << tag << ": " << velocity << std::endl;
    virtualMotorController->setVelocity(tag, velocity);
}
