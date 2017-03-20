#include "puzzle/puzzle.h"
#include "puzzle/printer.h"
#include "puzzle/dfs.h"

int main() {
    
    Puzzle::set_size(3);
    
    int arr [] = {1,2,0,3,4,5,6,7,8};
    
    Puzzle puzzle(arr);
    
    State state(puzzle);
    
    Node node(state);
    
    DFS dfs;
    
    dfs.search(&node);

    return 0;
}