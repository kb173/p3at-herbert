//
// Created by mathias on 30.04.19.
//

#include "AriaController.h"
#include "Aria.h"

// TODO: implement empty functions

bool AriaController::start(void *arg) {
    // FIXME: Causes a linker error
    // Aria::init();

    return false;
}

void AriaController::stop() {

}

bool AriaController::hasFailed() {
    return false;
}

void AriaController::stopActuators() {

}

int AriaController::robotStep(int period) {
    return 0;
}
