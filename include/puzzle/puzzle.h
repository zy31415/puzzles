//
// Created by zy on 3/13/17.
//

#ifndef INC_PUZZLES_PUZZLE_H
#define INC_PUZZLES_PUZZLE_H

#include <cstddef>
#include <vector>
#include <exception>
#include <memory>

using namespace std;

#define PUZZLE_SIZE 4

class IllegalMove : public exception {
public:
    const char * what() const throw() {
        return "Illegal move\n";
    }
};


enum Action {UP, RIGHT, DOWN, LEFT};


class Puzzle {
    static size_t puzzle_size;
    static size_t arr_length;

    // The index of the zero
    size_t index0;

    int* arr;
    
    // private copy constructor, make sure no accidental copy out of class
    Puzzle(const Puzzle &other);
    Puzzle& operator= (const Puzzle& other);

public:
    Puzzle();
    Puzzle(int* arr);
    ~Puzzle();
    
    bool equals(const Puzzle& other) const;
    bool operator == (const Puzzle& other) const;

    int at(int nrow, int ncol) const;

    static void set_size(size_t size);
    static size_t size();

    // Define actions:
    bool can_left() const;
    unique_ptr<Puzzle> left() const;

    bool can_right() const;
    unique_ptr<Puzzle> right() const;

    bool can_up() const;
    unique_ptr<Puzzle> up() const;

    bool can_down() const;
    unique_ptr<Puzzle> down() const;

};


#endif //INC_PUZZLES_PUZZLE_H
