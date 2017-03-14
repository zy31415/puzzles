cmake_minimum_required(VERSION 3.5.1)
project(puzzles)

include_directories(include)

set (CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory (src)
add_subdirectory (test)
enable_testing ()

add_test(NAME mytest COMMAND mytest)


