//
// Created by zy on 3/18/17.
//

#include <vector>

using namespace std;

#include "puzzle/state.h"

State::State() : Puzzle() {}

State::State(const Puzzle& puzzle): Puzzle(puzzle) {}

State State::goal;

// TODO: Use a static member to define goal.
bool State::is_goal() {
    return (*this) == goal;
}


