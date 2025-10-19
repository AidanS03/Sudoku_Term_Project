// ****************************************************************************
// Author: Aidan Stoner, Max Liberti                          File: cluster.hpp
// Date: 10/19/2025
// Class: CSCI-6626/CSCI-4526
// Description: A class that is composed of N related Squares, N being the game
//              size. One Cluster will relate all of the Squares in a single row, 
//              col, box, or diagonal (if playing diagonal mode). Each Square
//              will be associated with 3 Clusters
// ****************************************************************************
#ifndef CLUSTER_HPP
#define CLUSTER_HPP

// ****************************************************************************
#include "tools.hpp"
#include "square.hpp"
#include "board.hpp"
#include <memory>


// ****************************************************************************
// Cluster class
class Cluster{
    private:
        const char* type;
        Square* sqrs[9];
    public:
        Cluster(const char* t, Square* (&squares)[9]);
        ~Cluster() = default;
        ostream& print(ostream& out) const;
        void shoop(char val);
};

// ----------------------------------------------------------------------------
// Overloaded output operator for Cluster class
inline ostream& operator<<(ostream& out, const Cluster& clst ){ return clst.print(out);}

#endif //CLUSTER_HPP