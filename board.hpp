// ****************************************************************************
// Author: Aidan Stoner, Max Liberti                            File: board.hpp
// Date: 10/19/2025
// Class: CSCI-6626/CSCI-4526
// Description: Class to represent the Sudoku board, containing a dynamic array of
//              Square objects. Responsible for reading the puzzle from an input
//              file and providing access to individual squares.
// ****************************************************************************
// Header guard
#ifndef BOARD_HPP
#define BOARD_HPP

// ****************************************************************************
// Includes
#include "tools.hpp"
#include "square.hpp"
#include "cluster.hpp"
#include "exceptions.hpp"
#include "CanView.hpp"

using upCluster = unique_ptr<Cluster>;

// ****************************************************************************
// Enum class for types of clusters
enum class ClusterT{ROW, COL, BOX};

// ****************************************************************************
// Board class
class Board : public CanView {
    private:
        // data members
        ifstream& fin;
        int size;
        short int empty;
        Square* bd;
        vector<upCluster> clst;

        // member functions
        void getPuzzle();
        Square& sub(int r, int c);
        const Square& sub(int r, int c) const;
        Square& constSub(int r, int c) const;
        void makeClusters();
        void createRow(short j);
        void createCol(short k);
        void createBox(short j, short k);
    public:
        Board(ifstream& in, char type);
        ~Board() { delete[] bd; };
        ostream& print(ostream& out) const;
        void makeMove(int row, int col, char value);
        virtual char getMarkChar(int row, int col) const override;
        virtual string getPossibilityString(int row, int col) const override;
};

// ----------------------------------------------------------------------------
// Overloaded output operator for Board class
inline ostream& operator<<(ostream& out, const Board& bd){ return bd.print(out);}

#endif // BOARD_HPP