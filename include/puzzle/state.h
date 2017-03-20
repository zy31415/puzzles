//
// Created by zy on 3/18/17.
//

#ifndef PUZZLES_STATE_H
#define PUZZLES_STATE_H

#include <vector>
#include <memory>

using namespace std;

#include "puzzle.h"

class State : public Puzzle {

public:
    State(const Puzzle& puzzle);
    vector<State> next() const;
    bool is_goal();

    bool operator < (const State& other) const;

    bool operator == (const State& other) const;
};

#endif //PUZZLES_STATE_H
