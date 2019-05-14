//
// Created by irena.ankerl on 14.05.2019.
//

#include "catch.hpp"
#include "../Interfaces/IMotor.h"
#include "Motor.h"

SCENARIO("Motor") {
    GIVEN("A Motor") {

        auto motor = std::dynamic_pointer_cast<IMotor>
            (std::make_shared<Motor>(Motor()));

        WHEN("Motor is constructed") {

            THEN("The motors velocity, position and accelerations should be 0") {
                REQUIRE(motor->getVelocity() == 0);
                REQUIRE(motor->getPosition() == 0);
                REQUIRE(motor->getAcceleration() == 0);
            }
        }

        WHEN("Setting the velocity of the motor") {
            motor->setVelocity(5.5);

            THEN("The motor should have that velocity") {
                REQUIRE(motor->getVelocity() == 5.5);
            }
        }

        WHEN("Setting the position of the motor") {
            motor->setPosition(3.5);

            THEN("The motor should have that position") {
                REQUIRE(motor->getPosition() == 3.5);
            }
        }

        WHEN("Setting the acceleration of the motor") {
            motor->setAcceleration(4.2);

            THEN("The motor should have that acceleration") {
                REQUIRE(motor->getAcceleration() == 4.2);
            }
        }
    }
}