// ****************************************************************************
// Author: Aidan Stoner, Max Liberti
// Date: 9/17/2025
// Class: CSCI-6626/CSCI-4526
// Description: Main Game class for the Sudoku helper. Does the game control
//              and manages the board/actions with a menu system. Game settings
//              are read from an input file upon initialization.
// File: game.hpp
// ****************************************************************************
// Header guard
#ifndef GAME_HPP
#define GAME_HPP

// ****************************************************************************
// Includes
#include "tools.hpp"

// ****************************************************************************
// Game class

class Board;          // Forward declaration, will most likely be removed later

class Game {
    private:
        const string menu[6] = {"Mark: ", "Undo: ", "Redo: ", "Save: ", "Restore: ", "Quit: "};
        Board* brd;
        char type;
        short int size;
        ifstream& fin;
    public:
        Game(ifstream& in);
        ~Game() = default;
        void run();
};

#endif