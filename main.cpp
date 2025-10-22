// ****************************************************************************
// Author: Aidan Stoner, Max Liberti                             File: main.cpp
// Date: 9/25/2025
// Class: CSCI-6626/CSCI-4526
// Description: Command line based sudoku game, made for educational purposes.
// ****************************************************************************
// Includes & namespace
#include "tools.hpp"
#include "square.hpp"
#include "game.hpp"
#include "board.hpp"

// ****************************************************************************
// Function prototypes
void testState();
void testSquare(ostream& out);
void testBoard(ifstream& in, ostream& out);

// ****************************************************************************
int main(int argc, char* argv[]){
    banner();

    if(argc != 2) fatal(string("Usage: ") + argv[0] + " <input file>\n");
    cout << "Checking input file: " << argv[1] << endl;

    ifstream in(argv[1]);
    if(!in.is_open()) fatal(string("Can't open file ") + argv[1] + "\n");

    ofstream out("output.txt");
    if(!out.is_open()) fatal("Can't open output.txt\n");

    // testSquare(out);
    testBoard(in, out);

    in.clear();
    in.seekg(0, ios::beg);

    Game game(in);
    game.run();

    in.close();     
    out.close();

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

    cout << "Getting value from box2: " << box2.getValue() << endl;
}

// ----------------------------------------------------------------------------
// Test Square class
void testSquare(ostream& out) {
    out << "\nSquare class test:\n" << "Creating square1, not initialized:\n";
    Square square1;
    out << "Creating square2, initialized with a start value of '-', a row value of 1, and a column value of 2:\n";
    Square square2('-', 1, 2);

    out << "square1\n" << square1 << endl << "square2\n" << square2 << endl;

    out << "Marking square2 with '6':\n";
    square2.mark('6');
    out << square2 << endl;
}

// ----------------------------------------------------------------------------
// Test Board class
void testBoard(ifstream& in, ostream& out) {
    out << "\nBoard class test:" << endl;

    char fileType;
    in >> fileType;
    out << "File type code: " << fileType << endl;

    out << "Creating board from file:\n";
    Board board(in, fileType);

    out << "Board contents:\n";
    out << board << endl;

    out << "End of board test\n" << endl;
}
