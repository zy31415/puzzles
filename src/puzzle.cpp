//
// Created by zy on 3/13/17.
//

#include "puzzle/puzzle.h"

#include <algorithm>

using namespace std;

Puzzle::Puzzle(size_t size) : puzzle_size(size), arr_length(size*size) {
    arr = new int [arr_length];

    for (int ii=0; ii < arr_length; ii++)
        arr[ii] = ii;
    index0 = 0;
}

Puzzle::~Puzzle() {
    delete [] arr;
}

// copy constructor
Puzzle::Puzzle(const Puzzle& puzzle) : puzzle_size(puzzle.puzzle_size), arr_length(puzzle.arr_length) {
    arr = new int [arr_length];

    for (int ii=0; ii < arr_length; ii++)
        arr[ii] = puzzle.arr[ii];

    index0 = puzzle.index0;
}

int Puzzle::at(const int nrow, const int ncol) const {
    return arr[nrow * puzzle_size + ncol];
}

size_t Puzzle::size() const {
    return puzzle_size;
}

bool Puzzle::can_left() {
    return index0 % puzzle_size != 0;
}

Puzzle Puzzle::left() {
    if (can_left()) {
        swap(arr[index0-1], arr[index0]);
        index0 --;
    } else {
        throw IllegalMove();
    }
}

bool Puzzle::can_right() {
    return index0 % puzzle_size < puzzle_size - 1 ;
}

Puzzle Puzzle::right() {
    if (can_right()) {
        swap(arr[index0+1], arr[index0]);
        index0 ++;
    } else {
        throw IllegalMove();
    }
}

bool Puzzle::can_up() {
    return index0 / puzzle_size > 0;
}

Puzzle Puzzle::up() {
    if (can_up()) {
        swap(arr[index0-puzzle_size], arr[index0]);
        index0 -= puzzle_size;
    } else {
        throw IllegalMove();
    }
}

bool Puzzle::can_down() {
    return index0 / puzzle_size < puzzle_size - 1;
}

Puzzle Puzzle::down() {
    if (can_down()) {
        swap(arr[index0+puzzle_size], arr[index0]);
        index0 += puzzle_size;
    } else {
        throw IllegalMove();
    }
}

//////////////////////



