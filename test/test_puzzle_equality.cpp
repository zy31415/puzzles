//
// Created by zy on 3/13/17.
//


#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "puzzle/puzzle.h"

TEST_CASE("puzzle equality") {
    Puzzle::set_size(3);

    Puzzle p1;
    Puzzle p2;
    REQUIRE(p1.equals(p2));

    int arr [] = {1,0,2,3,4,5,6,7,8};
    Puzzle p3(arr);
    Puzzle p4(arr);

    REQUIRE(p3.equals(p4));

}

TEST_CASE("puzzle equality == ") {
    Puzzle::set_size(3);

    Puzzle p1;
    Puzzle p2;
    REQUIRE(p1 == p2);

    int arr [] = {1,0,2,3,4,5,6,7,8};
    Puzzle p3(arr);
    Puzzle p4(arr);

    REQUIRE(p3 == p4);

}
