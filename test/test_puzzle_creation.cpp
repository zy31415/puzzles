//
// Created by zy on 3/13/17.
//


#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "puzzle/puzzle.h"

TEST_CASE("puzzle creation: default"){
    Puzzle puzzle;

    for (int ii=0; ii < PUZZLE_SIZE ; ii++)
        for (int jj = 0; jj < PUZZLE_SIZE; jj++)
            REQUIRE(puzzle.at(0, 0) == 0);
}


TEST_CASE("puzzle creation: construct from an array.") {
    int arr1 [] = {15, 14, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    Puzzle puzzle1(arr1);
    REQUIRE(puzzle1.at(0,0) == 15);
    REQUIRE(puzzle1.at(0,1) == 14);

    int arr2 [] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 16};
    REQUIRE_THROWS(Puzzle ({arr2}));

    int arr3 [] = {0, 1, 1, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    REQUIRE_THROWS(Puzzle ({arr3}));

}

TEST_CASE("puzzle copy constructor") {
    Puzzle::set_size(3);

    Puzzle p1;

    Puzzle p2(p1);

    REQUIRE( p1 == p2);
}
