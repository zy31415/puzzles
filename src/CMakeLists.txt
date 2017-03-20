add_library (puzzle puzzle.cpp printer.cpp state.cpp node.cpp dfs.cpp explored_set.cpp)
add_executable (main main.cpp)
target_link_libraries (main puzzle)