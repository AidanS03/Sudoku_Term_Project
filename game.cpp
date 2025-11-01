// ****************************************************************************
// Author: Aidan Stoner, Max Liberti                             File: game.cpp
// Date: 9/25/2025
// Class: CSCI-6626/CSCI-4526
// Description: Main Game class for the Sudoku helper. Does the game control
//              and manages the board/actions with a menu system. Game settings
//              are read from an input file upon initialization.
// ****************************************************************************
// Includes
#include "game.hpp"

// ****************************************************************************
// Game class definitions

// ----------------------------------------------------------------------------
Game::
Game(ifstream& in) : fin(in){
    cout << "Creating game\n";
    static string codes = "sdtSDT";
    char code;
    fin >> code >> ws;

    if(codes.find(code) == string::npos) {
        cerr << "Invalid board type code: " << code << endl;
        throw BadBoardType("Invalid board type code: " + string(1, code));
    }
    type = tolower(code);
    cout << "Game type: " << type << endl;

    brd = new Board(fin, type);
    cout << "Game created successfully.\n";
}

// ----------------------------------------------------------------------------
// Run, main game loop
void Game::
run() {
    const string title = "Sudoku Term Project";
    int menu_items = 6;
    const string legal_choices = "MmZzYySsRrQq";

    for(;;) {
        char choice = toupper(menu_c(title, menu_items, menu, legal_choices));
        switch(choice) {
            case 'M':
                cout << "Case not yet implemented." << endl;
                break;
            case 'Z':
                cout << "Case not yet implemented." << endl;
                break;
            case 'Y':
                cout << "Case not yet implemented." << endl;
                break;
            case 'S':
                cout << "Case not yet implemented." << endl;
                break;
            case 'R':
                cout << "Case not yet implemented." << endl;
                break;
            case 'Q':
                cout << "Quitting the program." << endl;
                return;
        }
    }
}