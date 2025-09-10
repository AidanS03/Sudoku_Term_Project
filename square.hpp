// ****************************************************************************
// Author: Aidan Stoner, Max Liberti
// Date: 8/28/2025
// Class: CSCI-6626/CSCI-4526
// Description: This State class is used to represent the state of each box 
//              within the Sudoku grid. It contains useful information such  
//              as the possible values that the box could take and the actual 
//              value in the box.
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
inline ostream& operator<<(ostream& out, State& s){
    s.print(out);
    return out;
}

#endif // SQUARE_HPP