//
// Created by karl on 09.05.19.
//

#include "catch.hpp"
#include "../Interfaces/IVirtualDeviceManager.h"
#include "../Interfaces/IVirtualMotorController.h"
#include "VirtualMotorController.h"

SCENARIO("VirtualMotorController", "[controller]") {
    GIVEN("A DeviceManager with a motor, and a VirtualMotorController") {

        std::shared_ptr<IVirtualDeviceManager> deviceManager;
        VirtualMotorController motorController = VirtualMotorController(deviceManager);

        WHEN("Setting the velocity of the device via tag") {

        }
    }
}