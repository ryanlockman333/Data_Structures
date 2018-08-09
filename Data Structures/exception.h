/*
 * Ryan Lockman
 * 101430670
 * exception.h
 * Description: Exception Class Pototypes/Implementations
*/

// Macro
#ifndef EXCEPTION_H
#define EXCEPTION_H

// Headers
#include <string>

// Class
class Exception {
public:
    // Constructors
    Exception() : msg() {} // default
    Exception(std::string str) : msg(str) {};

    // Constant Member Functions
    const std::string what() const { return msg; }

private:
    // Data Members
    std::string msg;
};

#endif

