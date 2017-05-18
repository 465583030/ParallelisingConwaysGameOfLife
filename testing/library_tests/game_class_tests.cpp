#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include <catch.hpp>
#include "conway.h"

TEST_CASE("ConwaysGameOfLife", "[conway_lib]") {
    size_t gridWidth = 2;
    size_t gridHeight = 1;
    cgol::GameGridSharedPtrT grid = std::make_shared<cgol::GameGrid>(gridWidth, gridHeight);
    cgol::ConwaysGameOfLife game(grid);
    // TODO: simple 3x3 board

    SECTION("Constructor") {
        cgol::GameGridSharedPtrT nullGame;
        REQUIRE_THROWS_AS(cgol::ConwaysGameOfLife(nullGame), std::runtime_error);
    }

    SECTION("Run Nullptr Strategy") {
        REQUIRE_THROWS_AS(game.run(nullptr, 1), std::runtime_error);
    }

    SECTION("Run Negative Steps") {
        REQUIRE_THROWS_AS(game.run(cgol::strategyCPU, -1), std::runtime_error);
    }

    SECTION("Strategy CPU - Game Logic") {
        game.run(cgol::strategyCPU, 5);
    }
}

