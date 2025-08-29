// *****************************************************************************************
// Author: Aidan Stoner
// Date: 8/28/2025
// Class: CSCI-6626
// Description: This State class is used to represent the state of each box within
//              the Sudoku grid. It contains useful information such as the posisble 
//              values that the box could take and the actual value in the box
// *****************************************************************************************
// Header guard
#ifndef STATE_HPP
#define STATE_HPP

// *****************************************************************************************
// Includes
#include "tools.hpp"

// *****************************************************************************************
// State class
class State {
    private:
        // Private member variables
        short possibilities;
        char value;

    public:
        // Public constructors and destructors
        State();
        State(char startVal);
        ~State();

        void mark(char newVal);
        void print(ostream& out);
};

inline ostream& operator<<(ostream& out, State& s){
    s.print(out);
    return out;
}

#endif // STATE_HPP