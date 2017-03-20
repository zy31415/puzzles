//
// Created by zy on 3/18/17.
//

#include "puzzle/puzzle.h"
#include "puzzle/state.h"
#include "puzzle/node.h"

Node::Node(State state0): state(state0), parent(nullptr), action (Action::ZERO), path_cost(0){}

vector<Node*> Node::next() {
    vector<Node*> res;

    if (state.can_up()) {
        // TODO: Maybe can be replaced with a smart pointer?
        Node* node = new Node(state.up());
        node->action = Action::UP;
        node->parent = this;
        node->path_cost = this->path_cost + 1;

        res.push_back(node);
    }

    if (state.can_right()) {
        // TODO: Maybe can be replaced with a smart pointer?
        Node* node = new Node(state.right());
        node->action = Action::RIGHT;
        node->parent = this;
        node->path_cost = this->path_cost + 1;

        res.push_back(node);
    }

    if (state.can_down()) {
        // TODO: Maybe can be replaced with a smart pointer?
        Node* node = new Node(state.down());
        node->action = Action::DOWN;
        node->parent = this;
        node->path_cost = this->path_cost + 1;

        res.push_back(node);
    }

    if (state.can_left()) {
        // TODO: Maybe can be replaced with a smart pointer?
        Node* node = new Node(state.left());
        node->action = Action::LEFT;
        node->parent = this;
        node->path_cost = this->path_cost + 1;

        res.push_back(node);
    }

    return res;
}

bool Node::is_goal() {
    return state.is_goal();
}

State Node::get_state() const{
    return state;
}