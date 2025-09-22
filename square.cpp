// ****************************************************************************
// Author: Aidan Stoner, Max Liberti
// Date: 9/22/2025
// Class: CSCI-6626/CSCI-4526
// Description: This State class is used to represent the state of each squeare 
//              within the Sudoku grid. It contains useful information such 
//              as the posisble values that the square could take and the actual 
//              value in the square. The square class encapsulates the State class
//              and adds row and column information for each square.
// File: state.cpp
// ****************************************************************************
// Includes
#include "square.hpp"

// ****************************************************************************
// State class definitions

// ----------------------------------------------------------------------------
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

// ****************************************************************************
// Square class definitions

//-----------------------------------------------------------------------------
Square::
Square(char startVal, short int r, short int c) : st(startVal), row(r), col(c) {
    cerr << "Creating square [" << row << "," << col << "]" << endl;
}

// ----------------------------------------------------------------------------
// Destructor, prints deletion message
Square::
~Square(){
    cout << "Deleting square [" << row << "," << col << "]" << endl;
}

// ----------------------------------------------------------------------------
// Print all important information about the Square object
ostream& Square::
print(ostream& out) const {
    out << "Square [" << row << "," << col << "] ";
    st.print(out);
    return out;
}
