//
// Created by zy on 3/18/17.
//

#ifndef PUZZLES_DFS_H
#define PUZZLES_DFS_H

#include <memory>

using namespace std;

#include "node.h"


class DFS {

    Node* goal;

    size_t num_explored_set;

public:
    bool search(Node* node0);

    Node* get_goal();

    size_t get_num_explored_set();

    size_t num_frontier();

};

#endif //PUZZLES_DFS_H
