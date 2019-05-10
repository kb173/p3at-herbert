//
// Created by karl on 09.05.19.
//

#include "catch.hpp"
#include "../Interfaces/IVirtualDeviceManager.h"
#include "../Interfaces/IVirtualMotorController.h"
#include "VirtualMotorController.h"
#include "../Manager/VirtualDeviceManager.h"
#include "../Interfaces/IMotor.h"
#include "../Devices/Motor.h"

SCENARIO("VirtualMotorController", "[controller]") {
    GIVEN("A DeviceManager with a motor, and a VirtualMotorController") {

        auto deviceManager = std::dynamic_pointer_cast<IVirtualDeviceManager>
                (std::make_shared<VirtualDeviceManager>());
        auto motorController = std::dynamic_pointer_cast<IVirtualMotorController>
                (std::make_shared<VirtualMotorController>(deviceManager));
        auto motor = std::dynamic_pointer_cast<IMotor>
                (std::make_shared<Motor>(Motor()));

        deviceManager->attachDeviceToMap(0, std::dynamic_pointer_cast<IDevice>(motor));

        WHEN("Setting the velocity of the device via tag") {
            motorController->wbr_motor_set_velocity(0, 10);

            THEN("The device should have that velocity") {
                REQUIRE(motor->getVelocity() == 10);
            }
        }
    }
}