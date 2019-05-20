//
// Created by karl on 09.05.19.
//

#include "catch.hpp"
#include "../Interfaces/IVirtualDeviceManager.h"
#include "../Interfaces/IVirtualMotorController.h"
#include "VirtualMotorController.h"
#include "AriaController.h"
#include "../Manager/VirtualDeviceManager.h"
#include "../Interfaces/IMotor.h"
#include "../Devices/Motor.h"
#include "../Interfaces/IRealDeviceController.h"
#include "../Robots/P3AT.h"

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


/// Testing the whole ARIA library seems really hacky and doesn't work the way we inteded, which is why we decided not
/// unit test this framework
SCENARIO("AriaController", "[controller]") {
    GIVEN("An AriaController with given virtualRobot") {

        auto virtualRobot = std::dynamic_pointer_cast<IP3AT>
                (std::make_shared<P3AT>(20));
        auto ariaController = std::dynamic_pointer_cast<IRealDeviceController>
                (std::make_shared<AriaController>(virtualRobot));

        WHEN("Using the start method") {
            ariaController->start((void*)"-help");
            /*THEN("connectionStopped-field should be false") {
                REQUIRE(ariaController->hasFailed() == false);
            }*/
        }

        /*WHEN("Having started the robot the connectionStopped-bool should not be false") {

        }*/

    }
}

