// ****************************************************************************
// Author: Aidan Stoner, Max Liberti                            File: board.hpp
// Date: 10/19/2025
// Class: CSCI-6626/CSCI-4526
// Description: Class to represent the Sudoku board, containing a dynamic array of
//              Square objects. Responsible for reading the puzzle from an input
//              file and providing access to individual squares.
// ****************************************************************************
// Includes
#include "board.hpp"
#include <bitset>

// ****************************************************************************
// Indexed strings for enum ClusterT
static const char* clusterTStrings[3] = {"Row", "Column", "Box"};

// ****************************************************************************
// Board class definitions

Board::
Board(ifstream& in, char type) : fin(in){
    switch(type) {
        case 's':
            size = 6;
            break;
        case 'd':
        case 't':
            size = 9;
            break;
    }

    empty = size*size;

    bd = new Square[size*size];
    getPuzzle();

    makeClusters();

    for (int r = 1; r <= size; ++r) {
        for (int c = 1; c <= size; ++c) {
            Square& sqr = sub(r, c);
            char val = sqr.getValue();
            if (val >= '1' && val <= '9') {
                sqr.shoop(val);
            }
        }
    }
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
                throw BadInputFormat("Invalid character in puzzle input.");
            }
        }
    }

    char extra;
    if (fin >> extra) {
        throw InputTooLong("Input file contains more data than expected.");
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
// Read-only version of sub for use in const functions like getMarkChar
const Square& Board::
sub(int r, int c) const {
    int index = size * (r - 1) + (c - 1);
    return bd[index];
}

// ----------------------------------------------------------------------------
// Creates all the Clusters for the board
void Board::
makeClusters() {
    for(short j = 0; j < size; j++){
        createRow(j);
        if (j == 0) {
            for(short k = 0; k < size; k++){
                createCol(k);
            }
        }
    }
    for(short j = 0; j < size; j += 3) {
        for(short k = 0; k < size; k += 3){
            createBox(j, k);
        }
    }
}
// ----------------------------------------------------------------------------
// Creates a row Cluster for row j
void Board::
createRow(short j){
    Square* sqrs[9];
    const char* type = clusterTStrings[static_cast<int>(ClusterT::ROW)];
    for(short k = 0; k < size; k++) sqrs[k] = &bd[k + (j * size)];
    clst.push_back(make_unique<Cluster>(type, sqrs));
}

// ----------------------------------------------------------------------------
// Creates a column Cluster for column k
void Board::
createCol(short k){
    Square* sqrs[9];
    const char* type = clusterTStrings[static_cast<int>(ClusterT::COL)];
    for(short j = 0; j < size; j++) sqrs[j] = &bd[(j * size) + k];
    clst.push_back(make_unique<Cluster>(type, sqrs));
}

// ----------------------------------------------------------------------------
// Creates a box Cluster for box starting at (j,k)
void Board::
createBox(short j, short k ){
    Square* sqrs[9];
    const char* type = clusterTStrings[static_cast<int>(ClusterT::BOX)];

    int boxRow = j / 3;
    int boxCol = k / 3;

    int startRow = boxRow * 3;
    int startCol = boxCol * 3;

    int index = 0;
    for (short m = 0; m < size; m += 3) {
        for (short n = 0; n < size; n += 3) {
            if (m == startRow && n == startCol) {
                for (short p = 0; p < 3; p++) {
                    for (short q = 0; q < 3; q++) {
                        int row = startRow + p;
                        int col = startCol + q;
                        int boardIndex = row * size + col;
                        sqrs[index++] = &bd[boardIndex];
                    }
                }
            }
        }
    }
    clst.push_back(make_unique<Cluster>(type, sqrs));
}

// ----------------------------------------------------------------------------
// Allows user to make a move with the CLI
void Board::
makeMove(int row, int col, char value) {
    Square& sqr = sub(row, col);
    string possibleString = getPossibilityString(row, col);
    if (possibleString.find(value) != std::string::npos) {
        sqr.mark(value);
        sqr.shoop(value);
    } else {
        cout << "Value is impossible for this square." << endl;
    }
}

// ----------------------------------------------------------------------------
// Capture the board's current state into a Frame
Frame Board::
captureState() const {
    Frame fr(size);
    for (int r = 1; r <= size; ++r) {
        for (int c = 1; c <= size; ++c) {
            const Square& s = sub(r, c);
            const State& st = static_cast<const State&>(s);
        fr.addState(st, r, c);
        }
    }
    return fr;
}

// ----------------------------------------------------------------------------
// Restore the board's state from a Frame
void Board::
restoreState(const Frame& fr) {
    // Copy states back into squares
    for (int r = 1; r <= size; ++r) {
        for (int c = 1; c <= size; ++c) {
            Square& s = sub(r, c);
            const State& st = fr.getState(r, c);
            // Assign into the State part of Square
            static_cast<State&>(s) = st;
        }
    }
}

// ----------------------------------------------------------------------------
// Print all private data members in the Board object
ostream& Board::
print(ostream& out) const {
    for (int k = 1; k <= size; k++) {
        for (int j = 1; j <= size; j++) {
            int index = size * (k - 1) + (j - 1);
            out << bd[index];
        }
        out << endl;
    }

    out << "\nClusters:\n";
    for (const unique_ptr<Cluster>& cl : clst) {
        cl->print(out);
    }

    return out;
}

// ----------------------------------------------------------------------------
// Return character at certain row and column
char Board::
getMarkChar(int row, int col) const {
    const Square& sqr = sub(row, col);
    char value = sqr.getValue();

    if (value == '0' || value == '-') {
        return ' ';
    } else {
        return value;
    }
}

// ----------------------------------------------------------------------------
// Returns the possibilities for a certain square as a string
string Board::
getPossibilityString(int row, int col) const {
    const Square& sqr = sub(row, col);
    short options = sqr.getOptions();

    std::bitset<10> optionBits = options;
    std::string possibleString = "";

    for (int k = 1; k <= 9; ++k) {
        if (optionBits[k]) {
            possibleString += std::to_string(k);
        } else {
            possibleString += ' ';
        }
    }

    return possibleString;
}