#include "catch.hpp"
#include "../webots/include/controller/c/webots/robot.h"
#include "VirtualDeviceManager.h"

SCENARIO("Devices can be added to the map and the map can return a device to a given tag") {
    GIVEN("an object of VirtualDeviceManager with an empty map") {
        auto deviceManager = std::dynamic_pointer_cast<IVirtualDeviceManager>
                (std::make_shared<VirtualDeviceManager>());

        REQUIRE(deviceManager->getDevices().empty());
        REQUIRE(deviceManager->getDevices().size()==0);

        WHEN("a tag and an associated device are added to the map") {
            std::shared_ptr<IDevice> dev;
            deviceManager->attachDeviceToMap(0, dev);

            THEN("devices-map should not be empty") {
                REQUIRE(deviceManager->getDevices().empty() == false);
                REQUIRE(deviceManager->getDevices().size()>0);
            }

            THEN("getDeviceByTag should return the right device"){
                REQUIRE(dev == deviceManager->getDeviceByTag(0));
            }
        }
    }
}