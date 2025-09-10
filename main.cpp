// ****************************************************************************
// Author: Aidan Stoner, Max Liberti
// Date: 8/28/2025
// Class: CSCI-6626/CSCI-4526
// Description: Command line based sudoku game, made for educational purposes.
// File: main.cpp
// ****************************************************************************
// Includes & namespace
#include "tools.hpp"
#include "square.hpp"

// ****************************************************************************
// Function prototypes
void testState();

// ****************************************************************************
int main(int argc, char* argv[]){
    banner();

    testState();
    
    bye();

    return 0;
}


// ****************************************************************************
// Unit tests
// Test State class
void testState(){
    cout << "State class test:\n" << "Creating box1, initialized to '3':\n";
    State box1('3');
    cout << "Creating box2, initialized to '-':\n";
    State box2('-');
    cout << "Creating box3, not initialized:\n";
    State box3;
    cout << "Creating box4, initialized to 'x':\n";
    State box4('x');

    cout << "box1\n" << box1 << endl << "box2\n" << box2 << endl;
    cout << "box3\n" << box3 << endl << "box4\n" << box4 << endl;

    cout << "\nMarking box2 with '4':\n";
    box2.mark('4');
    cout << box2 << endl;

    cout << "\nMarking box2 with '5':\n";
    box2.mark('5');
    cout << box2 << endl;

    cout << "\nMarking box3 with '5':\n";
    box3.mark('5');
    cout << box3 << endl;

    cout << "\nMarking box4 with 'A':\n";
    box4.mark('A');
    cout << box4 << endl;
}
