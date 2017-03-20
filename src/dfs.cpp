//
// Created by zy on 3/18/17.
//

#include <memory>
#include <stack>
#include <set>

using namespace std;

#include "puzzle/node.h"

#include <puzzle/dfs.h>
#include "puzzle/explored_set.h"

bool DFS::search(Node* root) {

    // frontier is a collection of *nodes*
    stack<Node*> frontier;
    frontier.push(root);

    // explored_set is a collection of *states*
    ExploredSet explored_set;

    Node* node = nullptr;

    while (!frontier.empty()) {
        node = frontier.top();
        frontier.pop();

        if (explored_set.visited(*node))
            continue;

        explored_set.add(*node);

        if (node->is_goal()) {
            goal = node;

            num_explored_set = explored_set.size();

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

size_t DFS::get_num_explored_set() {
    return num_explored_set;
}