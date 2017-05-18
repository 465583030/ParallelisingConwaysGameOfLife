#include <catch.hpp>
#include <iostream>
#include "game_grid.h"


TEST_CASE("GameGrid Class Test", "[conway_lib]") {
    size_t gridWidth = 64;
    size_t gridHeight = 64;
    cgol::GameGrid generalGame(gridWidth, gridHeight);
    cgol::GridRawEntries generalRawEntries = generalGame.getRawEntries();

    SECTION("Constructor With Randomization") {
        REQUIRE_THROWS_AS(cgol::GameGrid(-1, 1), std::logic_error);
        REQUIRE_THROWS_AS(cgol::GameGrid(1, -1), std::logic_error);
        REQUIRE_THROWS_AS(cgol::GameGrid(-1, -1), std::logic_error);
        REQUIRE_THROWS_AS(cgol::GameGrid(cgol::GRID_MAX_WIDTH + 1, 1), std::logic_error);
        REQUIRE_THROWS_AS(cgol::GameGrid(1, cgol::GRID_MAX_HEIGHT + 1), std::logic_error);
    }

    SECTION("Constructor With Zeros") {
        size_t gridWidth = 2;
        size_t gridHeight = 2;
        cgol::GameGrid game(gridWidth, gridHeight, false);
        cgol::GridRawEntries rawEntries = game.getRawEntries();

        for(const auto& entry : rawEntries) REQUIRE(entry == 0);
    }

    SECTION("Constructor From Raw Data") {
        // TODO
    }

    SECTION("Entries Acquisition"){
        REQUIRE(generalGame.getWidth() == gridWidth);
        REQUIRE(generalGame.getHeight() == gridHeight);
        REQUIRE(generalRawEntries[5] == generalGame.getEntry(0, 5));
        REQUIRE(generalRawEntries[2 * gridWidth + 3] == generalGame.getEntry(2, 3));
    }

    SECTION("Entries Set Exceptions"){
        REQUIRE_THROWS_AS(generalGame.setEntry(2, 3, -1), std::runtime_error);
    }

}
