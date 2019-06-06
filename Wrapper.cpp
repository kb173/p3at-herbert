//
// Created by karl on 28.05.19.
//

#include "Wrapper.h"

std::shared_ptr<IRealDeviceController> Wrapper::controller = nullptr;

bool Wrapper::start(void *arg) {
    return controller->start(arg);
}

void Wrapper::stop() {
    controller->stop();
}

bool Wrapper::hasFailed() {
    return controller->hasFailed();
}

void Wrapper::stopActuators() {
    controller->stopActuators();
}

int Wrapper::robotStep(int period) {
    return controller->robotStep(period);
}

void Wrapper::setController(std::shared_ptr<IRealDeviceController> newController) {
    controller = newController;
}

const std::shared_ptr<IRealDeviceController> &Wrapper::getController() {
    return controller;
}
