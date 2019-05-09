#include "catch.hpp"
#include <webots/robot.h>

SCENARIO("Devices can be added to the map and the map can return a device to a given tag") {
    GIVEN("an object of VirtualDeviceManager with an empty map") {
        VirtualDeviceManager deviceManager;

        REQUIRE(deviceManager.empty());
        REQUIRE(deviceManager.size()==0);

        WHEN("a tag and an associated device are added to the map") {
            shared_ptr<IDevice> dev = new shared_ptr<IDevice>;

            WbDeviceTag test = wb_robot_get_device_by_index(1);
            deviceManager.attachDeviceToMap(test, dev);

            THEN("virtualManager should not be empty") {
                REQUIRE(deviceManager.empty() == false);
                REQUIRE(deviceManager.size()>0);
            }
        }
    }
}