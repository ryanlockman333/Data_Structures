/* 
 *clientsocket.cpp Class Implementations
*/

// Headers
#include <iostream>
#include <cstdlib>
#include <cstdio>  
#include "clientsocket.h"

// Constructors
ClientSocket::ClientSocket(std::string host, int port) {
    if(!Socket::create()) {
        perror("\nClient: create error");
        exit(EXIT_FAILURE);
    }  
    
    if(!Socket::connect(host, port)) {
        perror("\nClient: connect error");
        exit(EXIT_FAILURE);
    }    
}

// Overloaded Operators
const ClientSocket& ClientSocket::operator<<(const std::string &str) const {
    if(!Socket::send(str))
        perror("\nClient: send error"); 

    std::cout << "Client: sent: packet\n";
    return *this;
}

const ClientSocket& ClientSocket::operator>>(std::string &str) const {
    if(!Socket::recv(str))
        perror("\nClient: receive error"); 

    std::cout << "Client: received: packet\n"; 
    return *this;
}

