// ****************************************************************************
// Author: Aidan Stoner, Max Liberti
// Date: 8/28/2025
// Class: CSCI-6626/CSCI-4526
// Description: This State class is used to represent the state of each square 
//              within the Sudoku grid. It contains useful information such  
//              as the possible values that the square could take and the actual 
//              value in the square. The square class encapsulates the State class 
//              and adds row and column information for each square.
// File: state.hpp
// ****************************************************************************
// Header guard
#ifndef SQUARE_HPP
#define SQUARE_HPP

// ****************************************************************************
// Includes
#include "tools.hpp"

// ****************************************************************************
// State class
class State {
    private:
        // Private member variables
        short options;
        char value;

    public:
        // Public constructors and destructors
        State() = default;
        State(char startVal);
        ~State() = default;

        void mark(char newVal) { value = newVal; options = 0; }
        ostream& print(ostream& out) const;
        char getValue() const { return value; }
};

// ----------------------------------------------------------------------------
// Overloaded output operator for State class
inline ostream& operator<<(ostream& out, const State& st){ return st.print(out);}

// ****************************************************************************
// Square class
class Square {
    private:
        // Private member variables
        State st;
        short int row, col;

    public:
        // Public member functions
        Square() = default;
        Square(char startVal, short int r, short int c);
        ~Square();

        ostream& print(ostream& out) const;
        void mark(char newVal) { st.mark(newVal); }
};

// ----------------------------------------------------------------------------
// Overloaded output operator for Square class
inline ostream& operator<<(ostream& out, const Square& sq){ return sq.print(out);}

#endif // SQUARE_HPP