/*
socketexception.h class prototypes/implementations
*/

#ifndef SocketException_class
#define SocketException_class

// Headers
#include <string>

class SocketException {
public:
    // Constructors
    SocketException() : msg("") {} // default
    SocketException(std::string str) : msg(str) {};

    // Other Member Functions
    std::string what() { return msg; }

private:
    // Data Members
    std::string msg;
};

#endif

