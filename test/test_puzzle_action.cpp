//
// Created by zy on 3/13/17.
//

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "puzzle/puzzle.h"

#include <memory>

using namespace std;

TEST_CASE("puzzle action: can move") {
    Puzzle puzzle;

    REQUIRE(!puzzle.can_up());
    REQUIRE(puzzle.can_down());
    REQUIRE(!puzzle.can_left());
    REQUIRE(puzzle.can_right());

}

TEST_CASE("puzzle action: left 1") {
    int arr1[] = {1, 0, 2, 3, 4, 5, 6, 7, 8};
    int arr0[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};

    Puzzle::set_size(3);

    Puzzle puzzle0(arr0), puzzle1(arr1);

    REQUIRE(puzzle1.can_left());
    unique_ptr<Puzzle> ptr = puzzle1.left();

    REQUIRE(ptr->equals(puzzle0));
}

TEST_CASE("puzzle action: down"){

    Puzzle::set_size(3);

    Puzzle puzzle;

    // Test move down
    REQUIRE(puzzle.can_down());

    unique_ptr<Puzzle> ptr = puzzle.down();

    REQUIRE(ptr->at(0,0) == 3);
    REQUIRE(ptr->at(1,0) == 0);

    REQUIRE(ptr->can_down());
    ptr = ptr->down();

    REQUIRE(ptr->at(2, 0) == 0);

    REQUIRE(!ptr->can_down());

}


TEST_CASE("puzzle action: right"){
    Puzzle::set_size(3);

    Puzzle puzzle;

    // Test move down
    REQUIRE(puzzle.can_right());

    unique_ptr<Puzzle> ptr = puzzle.right();

    REQUIRE(ptr->at(0,0) == 1);
    REQUIRE(ptr->at(0,1) == 0);

    REQUIRE(ptr->can_right());
    ptr = ptr->right();

    REQUIRE(ptr->at(0, 2) == 0);

    REQUIRE(!ptr->can_right());

}

TEST_CASE("puzzle action: up"){
    Puzzle::set_size(3);

    int arr [] = {1,2,3,4,5,6,7,8,0};

    Puzzle puzzle(arr);

    // Test move down
    REQUIRE(puzzle.can_up());

    unique_ptr<Puzzle> ptr = puzzle.up();

    REQUIRE(ptr->at(2,2) == 6);
    REQUIRE(ptr->at(1,2) == 0);

    REQUIRE(ptr->can_up());
    ptr = ptr->up();

    REQUIRE(ptr->at(0, 2) == 0);

    REQUIRE(!ptr->can_up());

}

TEST_CASE("puzzle action: left 2"){
    Puzzle::set_size(3);

    int arr [] = {1,2,0,4,5,6,7,8,3};

    Puzzle puzzle(arr);

    // Test move down
    REQUIRE(puzzle.can_left());

    unique_ptr<Puzzle> ptr = puzzle.left();

    REQUIRE(ptr->at(0,2) == 2);
    REQUIRE(ptr->at(0,1) == 0);

    REQUIRE(ptr->can_left());
    ptr = ptr->left();

    REQUIRE(ptr->at(0, 0) == 0);

    REQUIRE(!ptr->can_left());

}

// TODO: Add other move tests


