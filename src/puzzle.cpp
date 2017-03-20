//
// Created by zy on 3/13/17.
//

#include "puzzle/puzzle.h"

#include <algorithm>
#include <cstring>
#include <vector>
#include <cassert>
#include <stdexcept>
#include <memory>
#include <iostream>

using namespace std;

size_t Puzzle::puzzle_size = PUZZLE_SIZE;
size_t Puzzle::arr_length = PUZZLE_SIZE * PUZZLE_SIZE;


shared_ptr<int> Puzzle::create_array() const {
    return shared_ptr<int> (new int[arr_length], std::default_delete<int[]>());
}

Puzzle::Puzzle() {
    arr = create_array();

    for (int ii=0; ii < arr_length; ii++)
        arr.get()[ii] = ii;

    index0 = 0;
}


Puzzle::Puzzle(int* arr) {
    this->arr = create_array();

    // Used to check repetition
    vector<bool> check(arr_length, true);

    for (size_t ii=0; ii < arr_length; ii++) {
        // do checks:
        if (arr[ii]<0 || arr[ii]>=arr_length) throw invalid_argument("Input out of range");
        if (!check[arr[ii]]) throw invalid_argument("Find duplicate.");
        check[arr[ii]] = false;

        this->arr.get()[ii] = arr[ii];

        if (arr[ii] == 0) index0 = ii;
    }
}

Puzzle::~Puzzle() {}

Puzzle::Puzzle(const Puzzle &other) {
    // Shallow copy
    this->arr = other.arr;
    this->index0 = other.index0;
}

Puzzle& Puzzle::operator=(const Puzzle &other) {
    // Shallow copy
    this->arr = other.arr;
    this->index0 = other.index0;
}

int& Puzzle::operator[](const size_t ii) {
    return arr.get()[ii];
}

Puzzle Puzzle::deepcopy() const {
    Puzzle puzzle;

    puzzle.arr = create_array();

    for (size_t ii=0; ii<arr_length; ii++) {
        puzzle.arr.get()[ii] = this->arr.get()[ii];
    }

    puzzle.index0 = this->index0;

    return puzzle;
}

bool Puzzle::equals(const Puzzle& other) const {

    if (this->arr_length != other.arr_length && this->puzzle_size != other.puzzle_size) return false;

    if (this->index0 != other.index0) return false;

    for (int ii=0; ii<this->arr_length; ii++) {
        if (this->arr.get()[ii] != other.arr.get()[ii]) return false;
    }
    return true;
}

bool Puzzle::operator==(const Puzzle& other) const {
    return equals(other);
}

int Puzzle::at(const int nrow, const int ncol) const {
    return arr.get()[nrow * puzzle_size + ncol];
}

void Puzzle::set_size(size_t size) {
    puzzle_size = size;
    arr_length = size*size;
}

size_t Puzzle::size() {
    return puzzle_size;
}

bool Puzzle::can_left() const{
    return index0 % puzzle_size != 0;
}

// Note that this function return an object and because return value optimization, there is actually no copying.
Puzzle Puzzle::left() const{
    Puzzle puzzle = deepcopy();
    swap(puzzle.arr.get()[index0-1], puzzle.arr.get()[index0]);
    puzzle.index0 --;
    return puzzle;
}

bool Puzzle::can_right() const{
    return index0 % puzzle_size < puzzle_size - 1 ;
}

Puzzle Puzzle::right() const{
    Puzzle puzzle = deepcopy();
    swap(puzzle.arr.get()[index0+1], puzzle.arr.get()[index0]);
    puzzle.index0 ++;
    return puzzle;
}

bool Puzzle::can_up() const{
    return index0 >= puzzle_size;
}

Puzzle Puzzle::up() const{
    Puzzle puzzle = deepcopy();
    swap(puzzle.arr.get()[index0-puzzle_size], puzzle.arr.get()[index0]);
    puzzle.index0 -= puzzle_size;
    return puzzle;    
}

bool Puzzle::can_down() const {
    return index0 < arr_length -  puzzle_size;
}

Puzzle Puzzle::down() const {
    Puzzle puzzle = deepcopy();
    swap(puzzle.arr.get()[index0+puzzle_size], puzzle.arr.get()[index0]);
    puzzle.index0 += puzzle_size;
    return puzzle;
}


//////////////////////



