// ****************************************************************************
// Author: Aidan Stoner, Max Liberti                       File: exceptions.hpp
// Date: 10/29/2025
// Class: CSCI-6626/CSCI-4526
// Description: Header file for custom exception classes used in the Sudoku
//              game project. Two main types of exceptions are game errors and
//              stream errors, both derived from std::exception.
// ****************************************************************************

#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

// ****************************************************************************
#include "tools.hpp"

// ****************************************************************************
// Generic GameError class
class GameError : public exception {
    public:
        GameError() = default;
        explicit GameError(const string& m) : msg(m) {}
        virtual void print() const {
            cerr << "Game Error occurred";
            if (!msg.empty()) cerr << ": " << msg;
            cerr << endl;
        }
        virtual ~GameError() noexcept = default;
    protected:
        string msg;
};

// ****************************************************************************
// Generic StreamError class
class StreamError : public exception {
    public:
        StreamError() = default;
        explicit StreamError(const string& m) : msg(m) {}
        virtual void print() const {
            cerr << "Stream Error occurred";
            if (!msg.empty()) cerr << ": " << msg;
            cerr << endl;
        }
        virtual ~StreamError() noexcept = default;
    protected:
        string msg;
};

// ****************************************************************************
// Specific stream errors
// ----------------------------------------------------------------------------
// Input file not in correct format
class BadInputFormat : public StreamError {
    public:
        explicit BadInputFormat(const string& m = "Input not in correct format") : StreamError(m) {}
        void print() const override { fatal("BadInputFormat: " + msg); }
};

// ----------------------------------------------------------------------------
// Input file longer than expected
class InputTooLong : public StreamError {
    public:
        explicit InputTooLong(const string& m = "Input file longer than expected") : StreamError(m) {}
        void print() const override { fatal("InputTooLong: " + msg); }
};

// ----------------------------------------------------------------------------
// Unable to open file
class FileOpenError : public StreamError {
    public:
        explicit FileOpenError(const string& path) : StreamError("Failed to open file: " + path) {}
        void print() const override { fatal("FileOpenError: " + msg); }
};

// ----------------------------------------------------------------------------
// Incorrect program arguments
class ArgError : public StreamError {
    public:
        explicit ArgError(const string& m = "Incorrect program arguments") : StreamError(m) {}
        void print() const override { fatal("ArgError: " + msg); }
};

// ****************************************************************************
// Specific game-logic errors
// ----------------------------------------------------------------------------
// Bad board type specified
class BadBoardType : public GameError {
    public:
        explicit BadBoardType(const string& m = "Bad board type") : GameError(m) {}
        void print() const override { fatal("BadBoardType: " + msg); }
};

// ----------------------------------------------------------------------------
// Move-related errors 
class MoveError : public GameError {
    public:
        explicit MoveError(const string& m = "Illegal move") : GameError(m) {}
        void print() const override { cerr << "MoveError: " << msg << endl; }
};

class MoveOutOfRange : public MoveError {
    public:
        MoveOutOfRange() : MoveError("Row/Column/Value out of range") {}
        void print() const override { cerr << "MoveOutOfRange: " << msg << endl; }
};

class CellAlreadyMarked : public MoveError {
    public:
        CellAlreadyMarked() : MoveError("Cell already has a value") {}
        void print() const override { cerr << "CellAlreadyMarked: " << msg << endl; }
};

class ValueNotPossible : public MoveError {
    public:
        ValueNotPossible() : MoveError("Value not in cell's possibilities") {}
        void print() const override { cerr << "ValueNotPossible: " << msg << endl; }
};

#endif //EXCEPTIONS_HPP