/* 
 *serversocket.h Class Prototypes
*/

#ifndef SERVERSOCKET_H
#define SERVERSOCKET_H

// Headers
#include "socket.h"

class ServerSocket : private Socket {
public:
    // Constructors
    ServerSocket() {};          // default
    ServerSocket(int port); 
    virtual ~ServerSocket() {}; // destructor

    // Overloaded Operators
    const ServerSocket& operator<<(const std::string &str) const; // send
    const ServerSocket& operator>>(std::string &str) const;       // receive
                              
    // Server Init                       
    void accept(ServerSocket &s);
};

#endif

