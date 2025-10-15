// ****************************************************************************
// Author: Aidan Stoner, Max Liberti                            File: board.hpp
// Date: 9/25/2025
// Class: CSCI-6626/CSCI-4526
// Description: Class to represent the Sudoku board, containing a dynamic array of
//              Square objects. Responsible for reading the puzzle from an input
//              file and providing access to individual squares.
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

    empty = size*size;

    bd = new Square[size*size];
    getPuzzle();
    cout << "Board created successfully.\n";
}

// ----------------------------------------------------------------------------
// Read the puzzle from the input file
void Board::
getPuzzle() {
    for (int j = 1; j <= size; j++) {
        for (int k = 1; k <= size; k++) {
            char ch;
            fin >> ch;
            if (ch == '-' || (ch >= '1' && ch <= '0' + size)) {
                sub(j, k) = Square(ch, j, k);
            } else {
                fatal("Invalid character: " + string(1, ch));
            }
        }
    }

    char extra;
    if (fin >> extra) {
        fatal("Error: Too many characters; bad input.\n");
    }
}

// ----------------------------------------------------------------------------
// Return a reference to the square at row r, column c
Square& Board::
sub(int r, int c) {
    int index = size * (r - 1) + (c - 1);
    return bd[index];
}

// ----------------------------------------------------------------------------
// Print all private data members in the Board object
ostream& Board::
print(ostream& out) const {
    for (int k = 1; k <= size; k++) {
        for (int j = 1; j <= size; j++) {
            int index = size * (k - 1) + (j - 1);
            out << bd[index] << " ";
        }
        out << endl;
    }

    return out;
}