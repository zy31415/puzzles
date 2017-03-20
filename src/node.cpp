//
// Created by zy on 3/18/17.
//

#include "puzzle/puzzle.h"
#include "puzzle/state.h"
#include "puzzle/node.h"

Node::Node(State state0): state(state0), parent(nullptr), action (Action::ZERO), path_cost(0){}

vector<Node*> Node::next() {
    vector<Node*> res;

    vector<Action> actions {Action::UP, Action::RIGHT, Action::DOWN, Action::LEFT};

    for (Action action : actions) {
        if (state.can_move(action)) {
            // TODO: Maybe can be replaced with a smart pointer?
            Node* node = new Node(state.move(action));
            node->action = action;
            node->parent = this;
            node->path_cost = this->path_cost + 1;
            res.push_back(node);
        }
    }

    return res;
}

bool Node::is_goal() {
    return state.is_goal();
}

State Node::get_state() const{
    return state;
}