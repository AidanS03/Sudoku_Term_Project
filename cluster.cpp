// ****************************************************************************
// Author: Aidan Stoner, Max Liberti                          File: cluster.cpp
// Date: 10/13/2025
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
Cluster::
Cluster(char& t, Square& squares){

}

// ----------------------------------------------------------------------------
// Print all data relevent to the Cluster class
ostream& Cluster::
print(ostream& out) const {
    out << type << endl;
    for( int k = 0; k < 9; k++){
        if(sqrs[k]) out << *sqrs[k] << endl;
        else out << "<null>" << endl;
    }
    return out;
}

// ----------------------------------------------------------------------------
// 
void Cluster::
shoop(char val){
    int v = int(val) - 48;
    for (int k = 0; k < 9; k++) sqrs[k]->turnOff(v);
}