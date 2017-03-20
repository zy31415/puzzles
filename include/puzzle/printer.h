//
// Created by zy on 3/13/17.
//

#ifndef PUZZLES_PRINTER_H
#define PUZZLES_PRINTER_H

#include "puzzle.h"
#include "node.h"

class PuzzlePrinter {
    static const int WIDTH = 3;
    static const char EMPTY_CHAR = '*';

    static void _node_print(const Node* node);

public:
    static void print(const Puzzle& puzzle);

    static void node_print(const Node& node);

};


#endif //PUZZLES_PRINTER_H
