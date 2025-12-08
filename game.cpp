// ****************************************************************************
// Author: Aidan Stoner, Max Liberti                             File: game.cpp
// Date: 9/25/2025
// Class: CSCI-6626/CSCI-4526
// Description: Main Game class for the Sudoku helper. Does the game control
//              and manages the board/actions with a menu system. Game settings
//              are read from an input file upon initialization.
// ****************************************************************************
// Includes
#include "game.hpp"

// ****************************************************************************
// Game class definitions

// ----------------------------------------------------------------------------
Game::
Game(ifstream& in) : fin(in){
    static string codes = "sdtSDT";
    char code;
    fin >> code >> ws;

    if(codes.find(code) == string::npos) {
        cerr << "Invalid board type code: " << code << endl;
        throw BadBoardType("Invalid board type code: " + string(1, code));
    }
    type = tolower(code);

    brd = new Board(fin, type);
    view = new Viewer(9, 9, *brd);

    view->show(cout);
}

Game::
~Game() {
    delete view;
    delete brd;
}

// ----------------------------------------------------------------------------
// Run, main game loop
void Game::
run() {
    const string title = "Sudoku Term Project";
    int menu_items = 6;
    const string legal_choices = "MmZzYySsRrQq";

    for(;;) {
        char choice = toupper(menu_c(title, menu_items, menu, legal_choices));
        switch(choice) {
            case 'M': {
                int r, c;
                char val;
                bool inputValid = false;

                while (!inputValid) {
                    cout << "Enter row (1-9), column (1-9), and value (1-9): ";

                    if (!(cin >> r >> c >> val)) {
                        cout << "Invalid format. Please enter numbers/characters correctly." << endl;
                        cin.clear();
                        cin.ignore(1000, '\n');
                        continue;
                    }

                    cin.ignore(1000, '\n');

                    if ((isdigit(val) && val > '0' && val <= '9') &&
                        (r > 0 && r <= 9) &&
                        (c > 0 && c <= 9)) {
                        inputValid = true;
                        } else {
                            cout << "Invalid range. Try again." << endl;
                        }
                }

                brd->makeMove(r, c, val);
                view->show(cout);
                break;
            }
            case 'Z':
                cout << "Case not yet implemented." << endl;
                break;
            case 'Y':
                cout << "Case not yet implemented." << endl;
                break;
            case 'S':
                cout << "Case not yet implemented." << endl;
                break;
            case 'R':
                cout << "Case not yet implemented." << endl;
                break;
            case 'Q':
                cout << "Quitting the program." << endl;
                return;
        }
    }
}