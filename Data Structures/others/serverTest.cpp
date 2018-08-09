/*
serverTest.cpp driver file
*/

// Headers
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "data.h"
#include "table.h" 
#include "socket.h"
#include "serversocket.h"
#include "socketexception.h"

int main(int argc, char **argv) {
    // Check Arguments
    if(argc < 2) {
        std::cout << "\nUsage: " << argv[0] << " [port]\n\n";
        return 1;
    }  

	// Declarations
	Table<Data> table;
	Data d;
    HashNode<Data> record, grab;
	unsigned int pin = 0;
    char buffer[256];
    std::string data;
    bool found = false;
    
    std::cout << "\nServer: waiting for connections...\n";

    // File to Write
    std::ofstream outFile("data.dat");
    if(!outFile) {
        std::cout << "\nError, opening file for writing\n";
        return -1;
    }  

    // Random Pin Numbers To File
    std::srand((unsigned)time(NULL)); 
    unsigned int count = 0, i = 0;

    while(++count <= 400) {
        i = (std::rand() % 9999)+1;
        outFile << i << "," << "Ryan,1472 S Balsam, 555-5555-5555, 1625344,\n";
    }
    outFile.close(); 

    // File to Read
    std::ifstream inFile("data.dat");
    if(!inFile) {
        std::cout << "\nError, opening file for reading\n";
        return -2;
    }  

    // Fill HashTable From File
    while(inFile.good()) {
        inFile.getline(buffer, 256, ',');
        record.setKey(atoi(buffer));
        
        inFile.getline(buffer, 256, ',');
        d.setName(buffer);
        inFile.getline(buffer, 256, ',');
        d.setAddr(buffer);
        inFile.getline(buffer, 256, ',');
        d.setPhone(buffer);
        inFile.getline(buffer, 256, ',');
        d.setSocial(buffer);

        record.setData(d);
    	table.insert(record);

        // Reset Record
        record = HashNode<Data>();
    }
    inFile.close();  

    try {
        ServerSocket server(atoi(argv[1])); // make listening socket  

        while(true) {                // make conversational socket
            ServerSocket new_sock;
            server.accept(new_sock); // wait for connection

            try {
                while(true) {       
                    new_sock >> data; // read in pin
                    std::cout << "Server: received: packet\n"; 
                    table.find(std::atoi(data.c_str()), found, grab); // check pin

                    if(found) {
                        new_sock  << "Access Granted\n";
                        std::cout << "Server: sent: packet\n";

                        new_sock  >> data; // menu dummy
                        std::cout << "Server: received: packet\n";

                        new_sock  << d.profileOut(); // send menu 
                        std::cout << "Server: sent: packet\n"; 
                        
                        while(true) { 
                            new_sock  >> data; // accept menu choice
                            std::cout << "Server: received: packet\n";

                            // Pocess Choice
                            switch(std::atoi(data.c_str())) {
                                case 1:
                                    new_sock  << grab.getData().getSocial();
                                    std::cout << "Server: sent: packet\n";
                                    break;
                                case 2:
                                    new_sock  << grab.getData().getPhone();
                                    std::cout << "Server: sent: packet\n";
                                    break;
                                case 3:
                                    new_sock  << grab.getData().getAddr();
                                    std::cout << "Server: sent: packet\n";
                                    break;
                                case 4:
                                    new_sock  << "4";
                                    std::cout << "Server: sent: packet\n";
                                    break;
                                default:
                                    new_sock  << "Error, invalid option\n";
                                    std::cout << "Server: received: packet\n";
                            }

                            if(data == "4") // break out of loop to not leak data
                                break;
                        }
                    }    
                    else
                        new_sock << "Access Denied\n";
                }
            }
            catch(SocketException&) {}
        }
    }
    catch(SocketException& se) {
        std::cout << "Exception was caught: " << se.description() << "\nExiting Now\n";
    }

  return 0;
}

