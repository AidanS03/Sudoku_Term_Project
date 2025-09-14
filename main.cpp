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
void testSquare();

// ****************************************************************************
int main(int argc, char* argv[]){
    banner();

    testState();

    testSquare();
    
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

    cout << "Getting value from box1: " << box1.getValue() << endl;
    cout << "Getting value from box2: " << box2.getValue() << endl;
    cout << "Getting value from box3: " << box3.getValue() << endl;
    cout << "Getting value from box4: " << box4.getValue() << endl;
}

void testSquare() {
    cout << "Square class test:\n" << "Creating square1, not initialized:\n";
    Square square1;
    cout << "Creating square2, initialized with a start value of 3, a row value of 1, and a column value of 2:\n";
    Square square2('3', 1, 2);
    cout << "Creating square3, initialized with a start value of 10, a row value of 0, and a column value of 11:\n";
    Square square3('10', 0, 11);

    cout << "square1\n" << square1 << endl << "square2\n" << square2 << endl;
    cout << "square3\n" << square3 << endl;

    cout << "\nMarking square2 with '5':\n";
    square2.mark('5');
    cout << square2 << endl;

    cout << "\nMarking square2 with 'A' (invalid):\n";
    square2.mark('A');
    cout << square2 << endl;
}
