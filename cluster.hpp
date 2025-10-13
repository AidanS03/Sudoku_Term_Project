// ****************************************************************************
// Author: Aidan Stoner, Max Liberti
// Date: 10/13/2025
// Class: CSCI-6626/CSCI-4526
// Description: A class that is composed of N related Squares, N being the game
//              size. One Cluster will relate all of the Squares in a single row, 
//              col, box, or diagonal (if playing diagonal mode). Each Square
//              will be associated with 3 Clusters
// File: cluster.hpp
// ****************************************************************************
#ifndef CLUSTER_HPP
#define CLUSTER_HPP

// ****************************************************************************
#include "tools.hpp"
#include "square.hpp"

// ****************************************************************************
// Cluster class
class Cluster{
    private:
        const char* type;
        Square* sqrs[9];
    public:
        Cluster();
        ~Cluster() = default;
        ostream& print(ostream& out);
        void shoop(char val);
};

#endif //CLUSTER_HPP