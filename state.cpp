// *****************************************************************************************
// Author: Aidan Stoner, Max Liberti
// Date: 8/28/2025
// Class: CSCI-6626/CSCI-4526
// Description: This State class is used to represent the state of each box within
//              the Sudoku grid. It contains useful information such as the posisble 
//              values that the box could take and the actual value in the box
// File: state.cpp
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
        cerr << "Error: Cell is already filled." << endl;
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

// *****************************************************************************************
// Function definitions
void testState(){
    cout << "State class test:\n" << "Creating box1, initialized to '3':\n";
    State box1('3');
    cout << "Creating box2, initialized to '-':\n";
    State box2('-');
    cout << "Creating box3, not initialized:\n";
    State box3;
    cout << "Creating box4, initialized to 'x':\n";
    State box4('x');

    cout << "box1\n" << box1 << endl << "box2\n" << box2 << endl << "box3\n" << box3 << endl << "box4\n" << box4 << endl;

    cout << "\nMarking box2 with '4':\n";
    box2.mark('4');
    cout << box2 << endl;

    cout << "\nMarking box2 with '5':\n";
    box2.mark('5');
    cout << box2 << endl;

    cout << "\nMarking box3 with 'A':\n";
    box3.mark('A');
    cout << box3 << endl;
}