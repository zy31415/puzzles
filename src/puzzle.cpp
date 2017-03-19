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

using namespace std;

size_t Puzzle::puzzle_size = PUZZLE_SIZE;
size_t Puzzle::arr_length = PUZZLE_SIZE * PUZZLE_SIZE;

Puzzle::Puzzle() {

    arr = new int [arr_length];

    for (int ii=0; ii < arr_length; ii++)
        arr[ii] = ii;
    index0 = 0;
}


Puzzle::Puzzle(int* arr) {

    this->arr = new int [arr_length];

    // Used to check repetition
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
Puzzle::Puzzle(const Puzzle& other) {
    arr = new int [arr_length];
    memcpy(this->arr, other.arr, sizeof(int)*arr_length);
    index0 = other.index0;
}

Puzzle& Puzzle::operator=(const Puzzle &other) {
    if (this != &other) {
        memcpy(this->arr, other.arr, sizeof(int)*arr_length);
    }
    return *this;
}

bool Puzzle::equals(const Puzzle& other) const {

    if (this->arr_length != other.arr_length && this->puzzle_size != other.puzzle_size) return false;

    if (this->index0 != other.index0) return false;

    for (int ii=0; ii<this->arr_length; ii++) {
        if (this->arr[ii] != other.arr[ii]) return false;
    }
    return true;
}

bool Puzzle::operator==(const Puzzle& other) const {
    return equals(other);
}

int Puzzle::at(const int nrow, const int ncol) const {
    return arr[nrow * puzzle_size + ncol];
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

unique_ptr<Puzzle> Puzzle::left() const{
    unique_ptr<Puzzle> puzzle(new Puzzle(*this));
    swap(puzzle->arr[index0-1], puzzle->arr[index0]);
    puzzle->index0 --;
    return puzzle;
}

bool Puzzle::can_right() const{
    return index0 % puzzle_size < puzzle_size - 1 ;
}

unique_ptr<Puzzle> Puzzle::right() const{
    unique_ptr<Puzzle> puzzle(new Puzzle(*this));
    
    swap(puzzle->arr[index0+1], puzzle->arr[index0]);
    puzzle->index0 ++;

    return puzzle;
}

bool Puzzle::can_up() const{
    return index0 >= puzzle_size;
}

unique_ptr<Puzzle> Puzzle::up() const{
    unique_ptr<Puzzle> puzzle(new Puzzle(*this));
    swap(puzzle->arr[index0-puzzle_size], puzzle->arr[index0]);
    puzzle->index0 -= puzzle_size;
    return puzzle;    
}

bool Puzzle::can_down() const {
    return index0 < arr_length -  puzzle_size;
}

unique_ptr<Puzzle> Puzzle::down() const {
    unique_ptr<Puzzle> puzzle(new Puzzle(*this));
    swap(puzzle->arr[index0+puzzle_size], puzzle->arr[index0]);
    puzzle->index0 += puzzle_size;
    return puzzle;
}

//////////////////////



