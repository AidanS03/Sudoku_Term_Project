// ****************************************************************************
// Author: Aidan Stoner, Max Liberti
// Date: 9/24/2025
// Class: CSCI-6626/CSCI-4526
// Description: 
// File: board.hpp
// ****************************************************************************
// Header guard
#ifndef BOARD_HPP
#define BOARD_HPP

// ****************************************************************************
// Includes
#include "tools.hpp"
#include "square.hpp"

// ****************************************************************************
// Board class
class Board {
    private:
        ifstream& fin;
        int size;
        short int empty = size*size;
        Square* bd;
        void getPuzzle();
    public:
        Board(ifstream& in, char type);
        ~Board() { delete[] bd; };
        Square& sub(int r, int c);
        ostream& print(ostream& out) const;
};

// ----------------------------------------------------------------------------
// Overloaded output operator for Board class
inline ostream& operator<<(ostream& out, const Board& bd){ return bd.print(out);}


#endif // BOARD_HPP