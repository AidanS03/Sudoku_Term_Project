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

        void mark(char newVal);
        void print(ostream& out);
        char getValue() const { return value; }
};

// ----------------------------------------------------------------------------
// Overloaded output operator for State class
inline ostream& operator<<(ostream& out, State& st){
    st.print(out);
    return out;
}

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
        Square(char startVal, short int r, short int c) : st(startVal) {}
        ~Square();

        void print(ostream& out);
        void mark(char newVal);
};

// ----------------------------------------------------------------------------
// Overloaded output operator for State class
inline ostream& operator<<(ostream& out, Square& sq){
    sq.print(out);
    return out;
}

#endif // SQUARE_HPP