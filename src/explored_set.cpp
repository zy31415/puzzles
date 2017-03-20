//
// Created by zy on 3/19/17.
//

#include <set>

using namespace std;

#include "puzzle/puzzle.h"

#include "puzzle/explored_set.h"


bool state_less(const State& s1, const State& s2) {
    int ii = 0;


    while (s1.at(ii) == s2.at(ii) && ii < Puzzle::length() - 1)
        ii++;

    return s1.at(ii) < s2.at(ii);
}


void ExploredSet::add(const Node& node) {
    explored_set.insert(node.get_state());
}

bool ExploredSet::visited(const Node &node) {
    return explored_set.count(node.get_state()) == 1;
}
