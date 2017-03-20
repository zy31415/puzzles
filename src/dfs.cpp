//
// Created by zy on 3/18/17.
//

#include <memory>
#include <stack>
#include <set>

using namespace std;

#include "puzzle/node.h"
#include "puzzle/state.h"

#include <puzzle/dfs.h>


bool DFS::search(Node* root) {

    // frontier is a collection of *nodes*
    stack<Node*> frontier;
    frontier.push(root);

    // explored_set is a collection of *states*
    set<State> explored_set;

    Node* node = nullptr;

    while (!frontier.empty()) {
        node = frontier.top();
        frontier.pop();

        if (explored_set.count(node->get_state()))
            continue;

        explored_set.insert(node->get_state());

        if (node->is_goal()) {
            goal = node;
            return true;
        }
        for (auto ni : node->next()) {
            frontier.push(ni);
        }
    }

    return false;
}


Node* DFS::get_goal() {
    return goal;
}