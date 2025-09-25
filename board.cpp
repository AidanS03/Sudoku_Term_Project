// ****************************************************************************
// Author: Aidan Stoner, Max Liberti
// Date: 9/25/2025
// Class: CSCI-6626/CSCI-4526
// Description: Class to represent the Sudoku board, containing a dynamic array of
//              Square objects. Responsible for reading the puzzle from an input
//              file and providing access to individual squares.
// File: board.cpp
// ****************************************************************************
// Includes
#include "board.hpp"

// ****************************************************************************
// Board class definitions

Board::
Board(ifstream& in, char type) : fin(in){
    cout << "Creating board of type " << type << endl;
    switch(type) {
        case 's':
            size = 6;
            break;
        case 'd':
        case 't':
            size = 9;
            break;
        default:
            fatal("Error: Invalid board type.\n");
    }

    bd = new Square[size*size];
    getPuzzle();
    cout << "Board created successfully.\n";
}

// ----------------------------------------------------------------------------
// Read the puzzle from the input file
void Board::
getPuzzle() {
    cout << "getPuzzle() called" << endl;   // using for debugging, remove when actually implemented
}

// ----------------------------------------------------------------------------
// Return a reference to the square at row r, column c
Square& Board::
sub(int r, int c) {
    
}

// ----------------------------------------------------------------------------
// Print all private data memebers in the Board object
ostream& Board::
print(ostream& out) const {
    out << "Board print() called" << endl;   // using for debugging, remove when actually implemented
    return out;
}