// *****************************************************************************************
// Author: Aidan Stoner
// Date: 8/28/2025
// Class: CSCI-6626
// Description: This State class is used to represent the state of each box within
//              the Sudoku grid. It contains useful information such as the posisble 
//              values that the box could take and the actual value in the box
// *****************************************************************************************
// Includes
#include "state.hpp"

// *****************************************************************************************
// State class definitions

State::~State(){
    // Destructor implementation (if needed)
}

State::State(){
    // Default constructor implementation (if needed)
}

State:: State(char startVal){
    if(startVal >= '1' && startVal <= '9'){
        value = startVal;                       // Initialized as filled box 
        possibilities = 0;                      // No possibilities left
    }else if(startVal == '-'){
        value = startVal;                       // Initialized as empty box
        possibilities = 0x3fe;                  // All numbers 1-9 are possible 
    }else{
        cerr << "Error: Invalid start value for State object." << endl;
    }
}

void State::mark(char newVal){
    if(value == '-'){
        value = newVal;                         // Set the value of the cell if empty
        possibilities = 0;                      // No possibilities left
    }else{
        cout << "Error: Cell is already filled." << endl;
    }
}

void State::print(ostream& out){
    // Print all important information about the State object
    out << "Value: " << value << endl << "Possibilities: ";
    for(int k = 9; k >= 1; k--){
        if(possibilities & (1 << k)){
            out << k;
        }else{
            out << "-";
        }
    }
    out << endl;
}