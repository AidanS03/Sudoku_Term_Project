#ifndef FRAME_HPP
#define FRAME_HPP

#include "square.hpp"

class Frame {
    public:
        Frame(int size) : n(size), states(new State[n*n]) {}

        // Deep copy semantics (Frame owns a dynamic State array)
        Frame(const Frame& other) : n(other.n), states(new State[other.n * other.n]) {
            for (int i = 0; i < n * n; ++i) states[i] = other.states[i];
        }

        Frame& operator=(const Frame& other) {
            if (this == &other) return *this;
            if (n != other.n) {
                delete[] states;
                n = other.n;
                states = new State[n * n];
            }
            for (int i = 0; i < n * n; ++i) states[i] = other.states[i];
            return *this;
        }

        Frame(Frame&& other) noexcept : n(other.n), states(other.states) {
            other.n = 0;
            other.states = nullptr;
        }

        Frame& operator=(Frame&& other) noexcept {
            if (this == &other) return *this;
            delete[] states;
            n = other.n;
            states = other.states;
            other.n = 0;
            other.states = nullptr;
            return *this;
        }

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