// ****************************************************************************
// Author: Aidan Stoner, Max Liberti                          File: cluster.cpp
// Date: 10/19/2025
// Class: CSCI-6626/CSCI-4526
// Description: A class that is composed of N related Squares, N being the game
//              size. One Cluster will relate all of the Squares in a single row, 
//              col, box, or diagonal (if playing diagonal mode). Each Square
//              will be associated with 3 Clusters
// ****************************************************************************
#include "cluster.hpp"

// ****************************************************************************
// Cluster class definitions

// ----------------------------------------------------------------------------
// Constructor, initializes type, adds given squares to the cluster, and adds
// this cluster to each of the squares
Cluster::
Cluster(const char* t, Square* (&squares)[9]) : type(t) {
    for(int k = 0; k < 9; k++){
        sqrs[k] = squares[k];
        sqrs[k]->addCluster(this);
    }
}

// ----------------------------------------------------------------------------
// Print all data relevant to the Cluster class
ostream& Cluster::
print(ostream& out) const {
    out << type << '\n';
    for( int k = 0; k < 9; k++){
        if(sqrs[k]) out << *sqrs[k];
        else out << "<null>\n"; 
    }
    return out;
}

// ----------------------------------------------------------------------------
// Eliminates a possible value from all Squares in the Cluster
// based on a newly marked value in one of the Squares of the Cluster
void Cluster::
shoop(char val){
    int v = int(val) - 48;
    for (int k = 0; k < 9; k++) sqrs[k]->turnOff(v);
}