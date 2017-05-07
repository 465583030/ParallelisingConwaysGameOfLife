#include <catch.hpp>
#include "game_grid.h"

TEST_CASE("GameGrid Class Test", "[conway_lib]") {

    SECTION("Constructor With Randomization") {
        REQUIRE_THROWS_AS(cgol::GameGrid(-1, 1), std::logic_error);
        REQUIRE_THROWS_AS(cgol::GameGrid(1, -1), std::logic_error);
        REQUIRE_THROWS_AS(cgol::GameGrid(-1, -1), std::logic_error);
        REQUIRE_THROWS_AS(cgol::GameGrid(cgol::GRID_MAX_WIDTH + 1, 1), std::logic_error);
        REQUIRE_THROWS_AS(cgol::GameGrid(1, cgol::GRID_MAX_HEIGHT + 1), std::logic_error);
    }

    SECTION("Constructor From File") {

    }

    SECTION("Entries Acquisition"){
        size_t gridWidth = 64;
        size_t gridHeight = 64;
        cgol::GameGrid game(gridWidth, gridHeight);
        cgol::GridRawEntries rawEntries = game.getRawEntries();

        REQUIRE(game.getWidth() == gridWidth);
        REQUIRE(game.getHeight() == gridHeight);
        REQUIRE(rawEntries[5] == game.getEntry(0, 5));
        REQUIRE(rawEntries[2 * gridWidth + 3] == game.getEntry(2, 3));
    }

}
