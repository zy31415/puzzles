//
// Created by zy on 3/13/17.
//

#ifndef INC_PUZZLES_PUZZLE_H
#define INC_PUZZLES_PUZZLE_H

#include <cstddef>
#include <vector>
#include <exception>

using namespace std;

#define DEFAULT_PUZZLE_SIZE 4

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
    Puzzle(size_t puzzle_size = DEFAULT_PUZZLE_SIZE);
    Puzzle(int* arr, size_t puzzle_size = DEFAULT_PUZZLE_SIZE);
    ~Puzzle();

    // copy constructor
    Puzzle(const Puzzle &puzzle);
    Puzzle& operator= (const Puzzle& other);

    int at(int nrow, int ncol) const;

    size_t size() const;

    // Define actions:
    bool can_left();
    bool left();

    bool can_right();
    bool right();

    bool can_up();
    bool up();

    bool can_down();
    bool down();

};


#endif //INC_PUZZLES_PUZZLE_H
