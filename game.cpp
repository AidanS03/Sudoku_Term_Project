// ****************************************************************************
// Author: Aidan Stoner, Max Liberti
// Date: 9/17/2025
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
// Constructor, initializes the game based on input file
Game::
Game(ifstream& in) : fin(in){
    static string codes = "sdtSDT";
    char code;
    in.get(code);

    string::size_type valid = codes.find(code);
    if(valid == codes.npos) fatal("Error: Invalid game type in input file.\n");

    type = tolower(code);
}

// ----------------------------------------------------------------------------
// Run, main game loop
void Game::
run(){

}