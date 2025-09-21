// ****************************************************************************
// Author: Aidan Stoner, Max Liberti
// Date: 8/28/2025
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
// Constructor, populates member variables based on startVal
State:: 
State(char startVal){
    if(startVal >= '1' && startVal <= '9'){
        value = startVal;             // Initialized as filled box 
        options = 0;                  // No possibilities left
    }else if(startVal == '-'){
        value = startVal;             // Initialized as empty box
        options = 0x3fe;              // All numbers 1-9 are possible 
    }else{
        cerr << "Error: Invalid start value for State object." << endl;
        value = '-';
        options = 0x3fe;
    }
}

// ----------------------------------------------------------------------------
// Marks an empty cell with a new value
void State::
mark(char newVal){
    if(value == '-'){
        value = newVal;               // Set the value of the cell if empty
        options = 0;                  // No possibilities left
    }else{
        cerr << "Error: Cell is already filled." << endl;
    }
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

// ----------------------------------------------------------------------------
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
