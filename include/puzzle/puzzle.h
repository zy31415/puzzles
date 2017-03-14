//
// Created by zy on 3/13/17.
//

#ifndef INC_PUZZLES_PUZZLE_H
#define INC_PUZZLES_PUZZLE_H

#include <cstddef>
#include <vector>
#include <exception>

using namespace std;


class IllegalMove : public exception {
public:
    const char * what() const throw() {
        return "Illegal move\n";
    }
};

class Puzzle {
    const size_t puzzle_size;
    const size_t arr_length;

    // The index of the zero
    size_t index0;

    int* arr;

public:
    Puzzle(size_t puzzle_size = 4);
    ~Puzzle();

    // copy constructor
    Puzzle(const Puzzle &puzzle);

    int at(int nrow, int ncol) const;

    size_t size() const;

    // Define actions:
    bool can_left();
    Puzzle left();

    bool can_right();
    Puzzle right();

    bool can_up();
    Puzzle up();

    bool can_down();
    Puzzle down();

};


#endif //INC_PUZZLES_PUZZLE_H
