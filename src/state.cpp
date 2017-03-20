//
// Created by zy on 3/18/17.
//

#include <vector>

using namespace std;

#include "puzzle/state.h"

State::State(const Puzzle& puzzle): Puzzle(puzzle) {}

vector<State> State::next() const{
    vector<State> res;

    if (can_up()) {
        res.push_back(up());
    }

    if (can_right()) {
        res.push_back(right());
    }

    if (can_down()) {
        res.push_back(down());
    }

    if (can_left()) {
        res.push_back(left());
    }

    return res;

}

// TODO: Use a static member to define goal.
bool State::is_goal() {
    for (int ii=0; ii<arr_length; ii++){
        if ((*this)[ii] == ii) return false;
    }
    return true;
}

bool State::operator<(const State &other) const {
    int ii = 0;
    for (ii=0; ii<arr_length; ii++) {
        if (arr.get()[ii] > other.arr.get()[ii])
            return false;
    }

    return arr.get()[ii] < other.arr.get()[ii];
}

bool State::operator==(const State &other) const {
    for (int ii=0; ii<arr_length; ii++) {
        if (arr.get()[ii] != other.arr.get()[ii])
            return false;
    }
    return true;
}
