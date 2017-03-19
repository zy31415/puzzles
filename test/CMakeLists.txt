cmake_minimum_required(VERSION 3.5.1)
project(mytest)

include_directories(/opt/Catch/include/)

add_executable(test_puzzle_creation test_puzzle_creation.cpp)
target_link_libraries(test_puzzle_creation puzzle)

add_executable(test_puzzle_action test_puzzle_action.cpp)
target_link_libraries(test_puzzle_action puzzle)

add_executable(test_puzzle_equality test_puzzle_equality.cpp)
target_link_libraries(test_puzzle_equality puzzle)

