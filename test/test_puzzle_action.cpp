//
// Created by zy on 3/13/17.
//


#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "puzzle/puzzle.h"


TEST_CASE("puzzle action: can move") {
    Puzzle puzzle;

    REQUIRE(!puzzle.can_up());
    REQUIRE(puzzle.can_down());
    REQUIRE(!puzzle.can_left());
    REQUIRE(puzzle.can_right());

}


TEST_CASE("puzzle action: down"){
    Puzzle puzzle;

    // Test move down
    REQUIRE(puzzle.can_down());
    REQUIRE(puzzle.down());
    REQUIRE(puzzle.at(0,0) == 4);
    REQUIRE(puzzle.at(1,0) == 0);

    REQUIRE(puzzle.can_down());
    REQUIRE(puzzle.down());

    REQUIRE(puzzle.can_down());
    REQUIRE(puzzle.down());

    REQUIRE(!puzzle.can_down());
    REQUIRE(!puzzle.down());

}

// TODO: Add other move tests


