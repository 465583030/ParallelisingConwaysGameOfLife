#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include <catch.hpp>
#include "conway.h"

TEST_CASE("ConwaysGameOfLife", "[conway_lib]") {
    size_t gridWidth = 64;
    size_t gridHeight = 64;
    cgol::GameGridSharedPtrT grid = std::make_shared<cgol::GameGrid>(gridWidth, gridHeight);
    cgol::ConwaysGameOfLife game(grid);

    SECTION("Constructor") {
        cgol::GameGridSharedPtrT nullGame;
        REQUIRE_THROWS_AS(cgol::ConwaysGameOfLife(nullGame), std::runtime_error);
    }

    SECTION("Strategy CPU") {
        game.run(cgol::strategyCPU, 5);
    }
}

