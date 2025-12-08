#ifndef FRAME_HPP
#define FRAME_HPP

#include "square.hpp"

class Frame {
    public:
        Frame(int size) : n(size) {states = new State[n*n];}
        ~Frame() {delete[] states;}
        ostream& print(ostream& out) const;
        void addState(const State& st, int r, int c);
    const State& getState(int r, int c) const;
    private:
        int n;
        State* states;
};

// ----------------------------------------------------------------------------
// Overloaded output operator for Frame class
inline ostream& operator<<(ostream& out, const Frame& fr) { return fr.print(out); }

#endif // FRAME_HPP