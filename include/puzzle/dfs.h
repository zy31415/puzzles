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

public:
    bool search(Node* node0);

    Node* get_goal();
};

#endif //PUZZLES_DFS_H
