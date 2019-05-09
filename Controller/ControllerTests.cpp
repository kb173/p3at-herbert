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
        std::shared_ptr<IVirtualMotorController> motorController = std::make_shared<IVirtualMotorController>(VirtualMotorController(deviceManager));

        WHEN("Setting the velocity of the device via tag") {


            THEN("The velocity of the device has changed") {
                REQUIRE(v.size() == 10);
                REQUIRE(v.capacity() >= 10);
            }
        }
        WHEN("the size is reduced") {
            v.resize(0);

            THEN("the size changes but not capacity") {
                REQUIRE(v.size() == 0);
                REQUIRE(v.capacity() >= 5);
            }
        }
        WHEN("more capaci