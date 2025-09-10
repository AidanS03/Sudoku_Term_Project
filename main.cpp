// *****************************************************************************************
// Author: Aidan Stoner
// Date: 8/28/2025
// Class: CSCI-6626
// Description: Command line based sudoku game, made for educational purposes.
// *****************************************************************************************
// Includes & namespace
#include "tools.hpp"
#include "square.hpp"

using namespace std;

// *****************************************************************************************
// Function prototypes
void stateClassTest();

// *****************************************************************************************
// Main 
int main(){
    banner();

    stateClassTest();
    
    bye();

    return 0;
}

// *****************************************************************************************
// Function definitions

void stateClassTest(){
    State box1('3');
    State box2('-');
    State box3;

    box1.print(cout);
    box2.print(cout);   
    box3.print(cout);

    box2.mark('4');
    cout << "\nAfter marking box2 with '4':\n" << box2 << endl;;
}