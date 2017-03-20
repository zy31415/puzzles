//
// Created by zy on 3/13/17.
//

#include "puzzle/printer.h"
#include <iostream>
#include <iomanip>

using namespace std;

void PuzzlePrinter::print(const Puzzle& puzzle) {

    cout << endl;

    size_t sz = puzzle.size();

    for (int ii = 0; ii < sz; ii++) {
        for (int jj = 0; jj < sz; jj++) {
            int num = puzzle.at(ii, jj);
            if (num != 0) {
                cout << setw(WIDTH) << num << ' ';
            } else {
                cout << setw(WIDTH) << EMPTY_CHAR << ' ';
            }

        }
        cout << endl;
    }
}

void PuzzlePrinter::node_print(const Node &node) {
    const Node* p = &node;

    while (true) {
        print(p->get_state());

        if (!p->parent) return;

        p = p->parent;
    }
}
