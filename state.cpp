// ****************************************************************************
// Author: Aidan Stoner, Max Liberti
// Date: 8/28/2025
// Class: CSCI-6626/CSCI-4526
// Description: This State class is used to represent the state of each box 
//              within the Sudoku grid. It contains useful information such 
//              as the posisble values that the box could take and the actual 
//              value in the box.
// File: state.cpp
// ****************************************************************************
// Includes
#include "state.hpp"

// ****************************************************************************
// State class definitions

// ----------------------------------------------------------------------------
// Constructor, populates member variables based on startVal
State:: State(char startVal){
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
void State::mark(char newVal){
    if(value == '-'){
        value = newVal;               // Set the value of the cell if empty
        options = 0;                  // No possibilities left
    }else{
        cerr << "Error: Cell is already filled." << endl;
    }
}

// ----------------------------------------------------------------------------
// Print all important information about the State object
void State::print(ostream& out){
    out << "Value: " << value << ", Options: ";
    for(int k = 9; k >= 1; k--){
        if(options & (1 << k)) out << k;
        else out << "-";
    }
    out << endl;
}