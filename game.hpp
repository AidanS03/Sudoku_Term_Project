// ****************************************************************************
// Author: Aidan Stoner, Max Liberti                            File: board.hpp
// Date: 9/25/2025
// Class: CSCI-6626/CSCI-4526
// Description: Main Game class for the Sudoku helper. Does the game control
//              and manages the board/actions with a menu system. Game settings
//              are read from an input file upon initialization.
// ****************************************************************************
// Header guard
#ifndef GAME_HPP
#define GAME_HPP

// ****************************************************************************
// Includes
#include "tools.hpp"
#include "board.hpp"
#include "Viewer.hpp"
#include "exceptions.hpp"
#include "stack.hpp"

// ****************************************************************************
// Game class

class Game {
    private:
        const string menu[6] = {"M: Mark ", "Z: Undo ", "Y: Redo ", "S: Save ", "R: Restore ", "Q: Quit "};
        Board* brd;
        Viewer* view;
        char type;
        short int size;
        ifstream& fin;
        Stack undoStack;
        Stack redoStack;
    public:
        Game(ifstream& in);
        ~Game();
        void run();
};

#endif