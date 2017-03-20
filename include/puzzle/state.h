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

protected:
    static State goal;

public:
    State();
    State(const Puzzle& puzzle);
    bool is_goal();

};

#endif //PUZZLES_STATE_H
