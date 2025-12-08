#include "frame.hpp"

// ****************************************************************************
// Add a State to the Frame at row r, column c
void Frame::
addState(const State& st, int r, int c) {
    int index = n * (r - 1) + (c - 1);
    states[index] = st;
}

// ----------------------------------------------------------------------------
// Get a State from the Frame at row r, column c
const State& Frame::
getState(int r, int c) const {
    int index = n * (r - 1) + (c - 1);
    return states[index];
}

// ----------------------------------------------------------------------------
// Print the frame (for debugging)
ostream& Frame::
print(ostream& out) const {
    for (int r = 1; r <= n; ++r) {
        for (int c = 1; c <= n; ++c) {
            int index = n * (r - 1) + (c - 1);
            out << states[index];
        }
        out << '\n';
    }
    return out;
}