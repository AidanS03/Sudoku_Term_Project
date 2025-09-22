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
#include "game.hpp"

// ****************************************************************************
// Function prototypes
void testState();
void testSquare();

// ****************************************************************************
int main(int argc, char* argv[]){
    banner();

    if(argc != 2) fatal(string("Usage: ") + argv[0] + " <input file>\n");
    cout << "Checking input file: " << argv[1] << endl;

    ifstream in(argv[1]);
    if(!in.is_open()) fatal(string("Can't open file ") + argv[1] + "\n");

    Game game(in);
    in.close();

    game.run();

    
    // testState();

    // testSquare();
    
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

    cout << "box1\n" << box1 << endl << "box2\n" << box2 << endl;
    cout << "box3\n" << box3 << endl;

    cout << "Marking box2 with '4':\n";
    box2.mark('4');
    cout << box2 << endl;

    cout << "Marking box2 with '5':\n";
    box2.mark('5');
    cout << box2 << endl;

    cout << "Getting value from box1: " << box1.getValue() << endl;
    cout << "Getting value from box2: " << box2.getValue() << endl;
}

// ----------------------------------------------------------------------------
// Test Square class
void testSquare() {
    cout << "\nSquare class test:\n" << "Creating square1, not initialized:\n";
    Square square1;
    cout << "Creating square2, initialized with a start value of '-', a row value of 1, and a column value of 2:\n";
    Square square2('-', 1, 2);
    cout << "Creating square3, initialized with a start value of 'A', a row value of 0, and a column value of 11:\n";
    Square square3('A', 0, 11);

    cout << "square1\n" << square1 << endl << "square2\n" << square2 << endl;
    cout << "square3\n" << square3 << endl;

    cout << "Marking square2 with 'A' (invalid):\n";
    square2.mark('A');
    cout << square2 << endl;

    cout << "Marking square2 with '5':\n";
    square2.mark('5');
    cout << square2 << endl;

    cout << "Marking square2 with '9' (invalid):\n";
    square2.mark('9');
    cout << square2 << endl;
}
