// ****************************************************************************
// Author: Aidan Stoner, Max Liberti                           File: square.cpp
// Date: 9/30/2025
// Class: CSCI-6626/CSCI-4526
// Description: This State class is used to represent the state of each squeare 
//              within the Sudoku grid. It contains useful information such 
//              as the posisble values that the square could take and the actual 
//              value in the square. The square class encapsulates the State class
//              and adds row and column information for each square.
// ****************************************************************************
// Includes
#include "square.hpp"
#include "cluster.hpp"

// ****************************************************************************
// State class definitions

State:: 
State(char startVal) : value(startVal) {
    if(value == '-') options = 0x3FE;
    else options = 0;
}

// ----------------------------------------------------------------------------
// Print all important information about the State object
ostream& State::
print(ostream& out) const {
    out << "Value: " << value << ", Options: ";
    for(int k = 9; k >= 1; k--){
        if(options & (1 << k)) out << k;
        else out << "-";
    }
    out << endl;
    return out;
}

// ----------------------------------------------------------------------------
// Remove one possible value the square could be
// Uses a mask with a binary string of 1s and a 0 in the nth slot
void State::
turnOff(int n) {
    if (n >= 0 && n <= 9) {
        short mask = ~(1 << n);
        options &= mask;
    } else {
        cout << "Invalid input. Cannot update possibilities." << endl;
    }
}


// ****************************************************************************
// Square class definitions

Square::
Square(char startVal, short int r, short int c) : st(startVal), row(r), col(c) {}

// ----------------------------------------------------------------------------
// Destructor
Square::
~Square(){}

// ----------------------------------------------------------------------------
// Print all important information about the Square object
ostream& Square::
print(ostream& out) const {
    out << "Square [" << row << "," << col << "] ";
    st.print(out);
    return out;
}

// ----------------------------------------------------------------------------
// Pushes cluster pointers into the Square's vector
void Square::
addCluster(Cluster* clstPointer) {
    clst.push_back(clstPointer);
}

// ----------------------------------------------------------------------------
// Changes possibility list of all neighboring squares
void Square::
shoop(char val) {
    for (Cluster* cl : clst) {
        cl->shoop(val);
    }
}

// ----------------------------------------------------------------------------
// Turns off position n in the square's possibility list
void Square::
turnOff(int n) {
    st.turnOff(n);
}

// ----------------------------------------------------------------------------
// Returns value of the square (read-only for the Board class)
char Square::
getValue() const {
    return value;
}

// ----------------------------------------------------------------------------
// Returns options for the square (read-only for the Board class)
short Square::
getOptions() const {
    return options;
}

