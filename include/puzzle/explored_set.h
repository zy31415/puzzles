//
// Created by zy on 3/19/17.
//

#ifndef PUZZLES_EXPLORED_SET_H
#define PUZZLES_EXPLORED_SET_H

#include <set>

using namespace std;


#include "node.h"


class ExploredSetBase {

public:

    virtual void add(const Node& node) = 0;

    virtual bool visited(const Node& node) = 0;

};


bool state_less(const State& s1, const State& s2);

class ExploredSet : public ExploredSetBase {

    set<State, bool(*)(const State&, const State&)> explored_set;

public:
    ExploredSet() : explored_set(state_less) {}

    void add(const Node& node);

    virtual bool visited(const Node& node);

};

#endif //PUZZLES_EXPLORED_SET_H
