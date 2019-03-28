#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "library.h"

TEST_CASE("Life, the universe and everything", "[42][theAnswer]") {
    REQUIRE(theAnswer() == 42);
}