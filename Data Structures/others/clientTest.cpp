/* 
clientTest.cpp driver file
*/

// Headers
#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include "clientsocket.h"
#include "socketexception.h"

int main(int argc, char **argv) {
    // Check Arguments
    if(argc < 3) {
        std::cout << "\nUsage: " << argv[0] << " [localhost] [port]\n\n";
        return 1;
    }

    // Declarations
	unsigned int pin = 0;
    std::string send, reply, menu;
    std::stringstream ss;

    try {
        ClientSocket client_socket(argv[1], atoi(argv[2])); // create the client socket

        try {
            // Prompt Pin
            std::cout << "\nEnter in your 4-digit pin: "; 
	        std::cin  >> pin; 
            ss        << pin;
            ss        >> send;
                
		    client_socket << send; // send pin
            std::cout     << "Client: sent: packet\n"; 
            
	        client_socket >> reply;
            std::cout     << "Client: received: packet\n";        
            std::cout     << "\nClient: received:  " << reply; 
        }
        catch(SocketException&) {}

        if(reply == "Access Granted\n") {
            client_socket << "menu"; // request menu
            std::cout     << "Client: sent: packet\n"; 
            
            client_socket >> menu;
            std::cout     << "Client: received: packet\n"; 

            // loop connection
            while(reply != "4") {
                std::cout << menu;
                std::cout << "\nMake Choice: ";
                std::cin  >> send;

                client_socket << send; // send menu choice
                std::cout << "Client: sent: packet\n"; 

                client_socket >> reply;
                std::cout << "Client: received: packet\n"; 
                std::cout << "\nClient: received: " << reply << "\n";
            }
	     }
    }    
    catch(SocketException& se) { 
        std::cout << "Exception was caught: " << se.description() << "\n";
    }

    std::cout << "\nGood Bye\n";
    return 0;
}

