//
// Created by zy on 3/18/17.
//

#ifndef PUZZLES_NODE_H
#define PUZZLES_NODE_H

#include <memory>

using namespace std;


#include "state.h"
#include "puzzle.h"


class Node {
    // use shared pointer, because a state could be shared by different node.
    shared_ptr<State> state;
    shared_ptr<Node> parent;
    Action action;
    size_t path_cost;

public:

    vector<shared_ptr<Node>> next();

    bool is_goal();

    shared_ptr<State> get_state();

};

#endif //PUZZLES_NODE_H
