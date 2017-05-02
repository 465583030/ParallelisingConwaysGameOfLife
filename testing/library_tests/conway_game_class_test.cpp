#include <catch.hpp>
#include "conway.h"

TEST_CASE("ConwaysGameOfLife Class Test", "[conway_lib]") {

    SECTION("Constructor") {
        REQUIRE_THROWS_AS(cgl::ConwaysGameOfLife(-1, 1), std::logic_error);
        REQUIRE_THROWS_AS(cgl::ConwaysGameOfLife(1, -1), std::logic_error);
        REQUIRE_THROWS_AS(cgl::ConwaysGameOfLife(-1, -1), std::logic_error);
        REQUIRE_THROWS_AS(cgl::ConwaysGameOfLife(cgl::GRID_MAX_WIDTH + 1, 1),
                          std::logic_error);
        REQUIRE_THROWS_AS(cgl::ConwaysGameOfLife(1, cgl::GRID_MAX_HEIGHT + 1),
                          std::logic_error);
    }


}
