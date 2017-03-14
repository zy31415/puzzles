cmake_minimum_required(VERSION 3.5.1)
project(mytest)

include_directories(/opt/Catch/include/)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES test.cpp)

add_executable(mytest ${SOURCES})