#include <iostream>

using namespace std;

#include "puzzle/printer.h"

#include "puzzle/puzzle.h"
#include "puzzle/dfs.h"

int main(int argc, char **argv) {

    size_t num_puzzles;
    size_t puzzle_size;

    cout << "======== START ============" << endl;

    cout << "Collect inputs ... " << endl;

    cout << "  Puzzle size: ";
    cin >> puzzle_size;
    cin.ignore(256,'\n');
    cout << endl;

    size_t arr_length = puzzle_size * puzzle_size;
    int* arr = new int [arr_length];

    cout << "  Puzzle configuration: " << endl;

    for (int ii=0; ii<arr_length; ii++)
        cin >> arr[ii];
    cin.ignore(256,'\n');

    cout << endl;

    Puzzle::set_size(puzzle_size);

    Puzzle puzzle(arr);

    delete [] arr;


    cout << "=====================" << endl;
    cout << "Your input: " << endl;
    PuzzlePrinter::print(puzzle);

    cout << "====================" << endl;
    cout << "Start to solve ..." << endl;

    State state0(puzzle);
    Node node0(state0);
    DFS dfs;



    if (dfs.search(&node0)) {
        cout << "Successful!" << endl;
        cout << "# of explored set: " << dfs.get_num_explored_set() << endl;
        PuzzlePrinter::node_print(*dfs.get_goal());

    } else {
        cout << "Failed." << endl;
    }

    cout << "======== END ==========" <<endl;
    return 0;
    
}