//
// Created by karl on 13.05.19.
//

#include "catch.hpp"
#include "../Interfaces/IP3AT.h"
#include "../Manager/VirtualDeviceManager.h"
#include "P3AT.h"

SCENARIO("P3AT", "[robot, p3at]") {
    GIVEN("A DeviceManager and a P3AT") {

        auto deviceManager = std::dynamic_pointer_cast<IVirtualDeviceManager>
                (std::make_shared<VirtualDeviceManager>());
        auto p3at = std::dynamic_pointer_cast<IP3AT>
                (std::make_shared<P3AT>(P3AT()));

        WHEN("Calling fillDeviceManager on the P3AT") {
            p3at->fillDeviceManager(deviceManager);

            THEN("Those devices should be in the DeviceManager") {
                REQUIRE(deviceManager->getDeviceByTag(0) != nullptr);
                REQUIRE(deviceManager->getDeviceByTag(1) != nullptr);
                REQUIRE(deviceManager->getDeviceByTag(10) != nullptr);
                REQUIRE(deviceManager->getDeviceByTag(17) != nullptr);
                REQUIRE(deviceManager->getDeviceByTag(20) != nullptr);
                REQUIRE(deviceManager->getDeviceByTag(27) != nullptr);
            }
        }
    }
}