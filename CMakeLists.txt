cmake_minimum_required(VERSION 3.21)
project(AI_Learning)

set(CMAKE_CXX_STANDARD 23)

add_executable(AI_Learning main.cpp STL/Vector.h Problems/Blocks_Problem.h Problems/Maze_Problem.h STL/Pair.h)
