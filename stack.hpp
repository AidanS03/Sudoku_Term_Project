#ifndef STACK_HPP
#define STACK_HPP

#include <vector>
#include "frame.hpp"

class Stack : private std::vector<Frame>{
    public:
        void pop() {this->vector::pop_back();}
        Frame* top() {return &this->vector::back();}
        void push(Frame* fr) {this->vector::push_back(*fr);}
        int size() {return this->vector::size();}
        void zap() {this->vector::clear();}
};

#endif // STACK_HPP