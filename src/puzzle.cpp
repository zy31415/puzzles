//
// Created by zy on 3/13/17.
//

#include "puzzle/puzzle.h"

#include <algorithm>
#include <cstring>
#include <vector>
#include <cassert>
#include <stdexcept>
#include <stdexcept>

using namespace std;

Puzzle::Puzzle(size_t size) : puzzle_size(size), arr_length(size*size) {
    arr = new int [arr_length];

    for (int ii=0; ii < arr_length; ii++)
        arr[ii] = ii;
    index0 = 0;
}

// TODO: This constructor function does almost no check. Add more checks:
Puzzle::Puzzle(int* arr, size_t size) : puzzle_size(size), arr_length(size*size) {
    this->arr = new int [arr_length];

    vector<bool> check(arr_length, true);

    for (size_t ii=0; ii < arr_length; ii++) {
        // do checks:
        if (arr[ii]<0 || arr[ii]>=arr_length) throw invalid_argument("Input out of range");
        if (!check[arr[ii]]) throw invalid_argument("Find duplicate.");
        check[arr[ii]] = false;

        this->arr[ii] = arr[ii];

        if (arr[ii] == 0) index0 = ii;
    }
}

Puzzle::~Puzzle() {
    delete [] arr;
}

// copy constructor
Puzzle::Puzzle(const Puzzle& puzzle) : puzzle_size(puzzle.puzzle_size), arr_length(puzzle.arr_length) {
    arr = new int [arr_length];
    memcpy(this->arr, puzzle.arr, sizeof(int)*arr_length);
    index0 = puzzle.index0;
}

Puzzle& Puzzle::operator=(const Puzzle &other) {
    if (this != &other) {
        memcpy(this->arr, other.arr, sizeof(int)*arr_length);
    }
    return *this;
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

bool Puzzle::left() {
    if (can_left()) {
        swap(arr[index0-1], arr[index0]);
        index0 --;
        return true;
    }

    return false;
}

bool Puzzle::can_right() {
    return index0 % puzzle_size < puzzle_size - 1 ;
}

bool Puzzle::right() {
    if (can_right()) {
        swap(arr[index0+1], arr[index0]);
        index0 ++;
        return true;
    }

    return false;
}

bool Puzzle::can_up() {
    return index0 / puzzle_size > 0;
}

bool Puzzle::up() {
    if (can_up()) {
        swap(arr[index0-puzzle_size], arr[index0]);
        index0 -= puzzle_size;
        return true;
    }

    return false;
}

bool Puzzle::can_down() {
    return index0 / puzzle_size < puzzle_size - 1;
}

bool Puzzle::down() {
    if (can_down()) {
        swap(arr[index0+puzzle_size], arr[index0]);
        index0 += puzzle_size;
        return true;
    }

    return false;
}

//////////////////////



