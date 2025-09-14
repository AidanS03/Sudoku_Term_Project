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

// ****************************************************************************
// Square class definitions

// ----------------------------------------------------------------------------
// Constructor, populates member variables based on startVal, r, and c
Square:: Square(char startVal, short int r, short int c) : st(startVal){
    bool r_valid = false;
    bool c_valid = false;

    if(r >= 1 && r <= 9) row = r, r_valid = true;
    else cerr << "Error: Invalid row value for Square object." << endl, row = 0;

    if(c >= 1 && c <= 9) col = c, c_valid = true;
    else cerr << "Error: Invalid column value for Square object." << endl, col = 0;

    if (r_valid && c_valid) {
        cout << "Square [" << row << "," << col << "] created." << endl;
    } else {
        cerr << "Error: Invalid input for Square." << endl;

    }
}

// ----------------------------------------------------------------------------
Square::~Square(){
    cout << "Deleting square [" << row << "," << col << "]" << endl;
}

// ----------------------------------------------------------------------------
// Marks the square's state with a new value
void Square::mark(char newVal){
    if(newVal >= '1' && newVal <= '9') {
        st.mark(newVal);
    } else {
        cerr << "Error: Invalid value for Square object." << endl;
    }

}

// ----------------------------------------------------------------------------
// Print all important information about the Square object
void Square::print(ostream& out){
    out << "Square [" << row << "," << col << "] ";
    st.print(out);
}