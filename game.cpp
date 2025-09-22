// ****************************************************************************
// Author: Aidan Stoner, Max Liberti
// Date: 9/22/2025
// Class: CSCI-6626/CSCI-4526
// Description: Main Game class for the Sudoku helper. Does the game control
//              and manages the board/actions with a menu system. Game settings
//              are read from an input file upon initialization.
// File: game.cpp
// ****************************************************************************
// Includes
#include "game.hpp"

// ****************************************************************************
// Game class definitions

// ----------------------------------------------------------------------------
Game::
Game(ifstream& in) : fin(in){
    static string codes = "sdtSDT";
    char code;
    fin >> code >> ws;

    if(!fin.fail()){
        if(codes.find(code) == string::npos) fatal("Error: Invalid game type in input file.\n");
        type = tolower(code);
        cout << "Game type: " << type << endl;
    }else fatal("Error: Failed to read input file.\n");
}

// ----------------------------------------------------------------------------
// Run, main game loop
void Game::
run() {
    bool isRunning = true;
    const string title = "Sudoku Term Project";
    int menu_items = 6;
    const string legal_choices = "MmZzYySsRrQq";

    while (isRunning) {
        char choice = menu_c(title, menu_items, menu, legal_choices);
        switch(toupper(choice)) {
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
                isRunning = false;
                break;
        }
    }
}