cmake_minimum_required(VERSION 3.20)

project(Sudoku_Term_Project)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(Sudoku_Term_Project
        main.cpp
        game.cpp
        game.hpp
        square.cpp
        square.hpp
        tools.cpp
        tools.hpp
)