//
// Created by irena.ankerl on 14.05.2019.
//

#include "catch.hpp"
#include "Converter.h"
#include "../Interfaces/IConverter.h"

SCENARIO("Converter") {
    GIVEN("A converter") {

        auto converter = std::dynamic_pointer_cast<IConverter>
                (std::make_shared<Converter>(Converter()));

        WHEN("Radian/s and the wheel radius (in mm) are given to 'radToMM'") {

            double radian = 3;
            double radius = 110;

            THEN("The converter should return mm/s") {
                REQUIRE(converter->radToMm(radius, radian) == 330);
            }
        }
    }
}