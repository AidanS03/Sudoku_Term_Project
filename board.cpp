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

// ****************************************************************************
// Indexed strings for enum ClusterT
static const char* clusterTStrings[3] = {"Row", "Column", "Box"};

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

    makeClusters();
    cout << "Clusters made successfully.\n";
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
// Creates all the Clusters for the board
void Board::
makeClusters() {
    cout << "Making clusters...\n";
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
    // cout << "Row cluster created successfully.\n";
}

// ----------------------------------------------------------------------------
// Creates a column Cluster for column k
void Board::
createCol(short k){
    Square* sqrs[9];
    const char* type = clusterTStrings[static_cast<int>(ClusterT::COL)];
    for(short j = 0; j < size; j++) sqrs[j] = &bd[(j * size) + k];
    clst.push_back(make_unique<Cluster>(type, sqrs));
    // cout << "Column cluster created successfully.\n";
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
    // cout << "Box cluster created successfully.\n";
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