/*
 *serversocket.cpp Class Implementations
*/

// Headers
#include <iostream>
#include <cstdlib>
#include <cstdio>  
#include "serversocket.h"

// Constructors
ServerSocket::ServerSocket(int port) {
    if(!Socket::create()) {
        perror("\nServer: create error");
        exit(EXIT_FAILURE);
    }

    if(!Socket::bind(port)) {
        perror("\nServer: bind error");
        exit(EXIT_FAILURE);
    }

    if(!Socket::listen()) {
        perror("\nServer: listen error");
        exit(EXIT_FAILURE);
    }
}
              
// Overloaded Operators             
const ServerSocket& ServerSocket::operator<<(const std::string &str) const {
    if(!Socket::send(str))
        perror("\nServer: send error");
  
    std::cout << "Server: sent: packet\n"; 
    return *this;
}

const ServerSocket& ServerSocket::operator>>(std::string &str) const {
    if(!Socket::recv(str))
        perror("\nServer: receive error");

    std::cout << "Server: received: packet\n"; 
    return *this;
}

// Server Init
void ServerSocket::accept(ServerSocket &s) {
    if(!Socket::accept(s))
        perror("\nServer: accept error");
}

