//
// Created by zy on 3/18/17.
//

#include <vector>

using namespace std;

#include "puzzle/state.h"

State::State(shared_ptr<Puzzle> puzzle) {
    this->puzzle = puzzle;
}

vector<State> State::next() {

    vector<State> res;

    for (auto ii : puzzle->next()) {
        State state(make_shared<Puzzle>(ii));
        res.push_back(state);
    }

    return res;

}

bool State::is_goal() {
    return puzzle->is_goal();
}

bool State::operator<(const State &other) const {
    return true;
}

bool State::operator==(const State &other) const {
    return true;
} 
