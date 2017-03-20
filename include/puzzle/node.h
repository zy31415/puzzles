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

public:
    // use shared pointer, because a state could be shared by different node.
    State state;
    Node* parent;
    Action action;
    size_t path_cost;

    Node(State state0);

    vector<Node*> next();

    bool is_goal();

    State get_state() const;

};

#endif //PUZZLES_NODE_H
