//
// Created by zy on 3/13/17.
//

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "puzzle/puzzle.h"

#if defined PUZZLE_SIZE
#undef PUZZLE_SIZE
#endif

#define PUZZLE_SIZE 3


TEST_CASE("puzzle action: can move") {
    Puzzle puzzle;

    REQUIRE(!puzzle.can_up());
    REQUIRE(puzzle.can_down());
    REQUIRE(!puzzle.can_left());
    REQUIRE(puzzle.can_right());

}

TEST_CASE("puzzle action: left") {
    int arr1[] = {1, 0, 2, 3, 4, 5, 6, 7, 8};
    int arr0[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};

    Puzzle::set_size(3);

    Puzzle puzzle0(arr0), puzzle1(arr1);

    REQUIRE(!puzzle1.can_left());
    REQUIRE(puzzle1.left() == puzzle0);
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


