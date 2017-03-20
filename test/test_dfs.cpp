//
// Created by zy on 3/19/17.
//

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "puzzle/puzzle.h"
#include "puzzle/state.h"
#include "puzzle/node.h"
#include "puzzle/dfs.h"
#include "puzzle/printer.h"

TEST_CASE( "dfs") {
    Puzzle::set_size(3);

    int arr [] = {1,2,0,3,4,5,6,7,8};

    Puzzle puzzle(arr);

    State state(puzzle);

    Node node(state);

    DFS dfs;

    dfs.search(&node);

    PuzzlePrinter::node_print(*dfs.get_goal());
}