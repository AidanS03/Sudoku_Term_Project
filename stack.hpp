#ifndef STACK_HPP
#define STACK_HPP

#include <vector>
#include "frame.hpp"

class Stack : private std::vector<Frame>{
    public:
    void pop() { this->vector::pop_back(); }
    Frame& top() { return this->vector::back(); }
    const Frame& top() const { return this->vector::back(); }
    void push(const Frame& fr) { this->vector::push_back(fr); }
    void push(Frame&& fr) { this->vector::push_back(std::move(fr)); }

    int size() const { return static_cast<int>(this->vector::size()); }
    void zap() { this->vector::clear(); }
};

#endif // STACK_HPP