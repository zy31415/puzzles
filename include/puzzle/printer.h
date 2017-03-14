//
// Created by zy on 3/13/17.
//

#ifndef PUZZLES_PRINTER_H
#define PUZZLES_PRINTER_H

#include "puzzle.h"

class PuzzlePrinter {
    static const int WIDTH = 3;
    static const char EMPTY_CHAR = '*';
public:
    static void print(const Puzzle& puzzle);
};


#endif //PUZZLES_PRINTER_H
