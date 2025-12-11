// ****************************************************************************
// Author: Aidan Stoner, Max Liberti                           File: square.hpp
// Date: 8/28/2025
// Class: CSCI-6626/CSCI-4526
// Description: This State class is used to represent the state of each square 
//              within the Sudoku grid. It contains useful information such  
//              as the possible values that the square could take and the actual 
//              value in the square. The square class encapsulates the State class 
//              and adds row and column information for each square.
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
    protected:
        // Protected member variables
        short options=511; // This value is binary '111111111'
        char value='0';

    public:
        // Public constructors and destructors
        State() = default;
        State(char startVal);
        ~State() = default;

        // Copy assignment operator
        State& operator=(const State& other) {
            if (this != &other) {
                options = other.options;
                value = other.value;
            }
            return *this;
        }

        void mark(char newVal) { value = newVal; options = 0; }
        ostream& print(ostream& out) const;
        void turnOff(int n);

};

// ----------------------------------------------------------------------------
// Overloaded output operator for State class
inline ostream& operator<<(ostream& out, const State& st){ return st.print(out);}

// ****************************************************************************
// Forward decaration for Cluster class, prevents circular include
class Cluster;

// ----------------------------------------------------------------------------
// Square class
class Square : public State {
    private:
        // Private member variables
        short int row, col;
        vector<Cluster*> clst;

    public:
        // Public member functions
        Square() = default;
        Square(char startVal, short int r, short int c);
        ~Square();

        ostream& print(ostream& out) const;
        void mark(char newVal) { State::mark(newVal); }
        void turnOff(int n);
        void addCluster(Cluster*);
        void shoop(char val);
        char getValue() const;
        short getOptions() const;
};

// ----------------------------------------------------------------------------
// Overloaded output operator for Square class
inline ostream& operator<<(ostream& out, const Square& sq){ return sq.print(out);}

#endif // SQUARE_HPP