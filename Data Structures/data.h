/*
Ryan
Data Record Class Header Prototypes/Implementations
*/

// Macro
#ifndef DATA_H
#define DATA_H

// Headers
#include <iostream>
#include <string>

class Data {
public:
	// Constructors
	Data() : name(""), addr(""), phone(""), social("") {} // default
	Data(std::string name, std::string addr, std::string phone, std::string social)
         : name(name), addr(addr), phone(phone), social(social) {}

	// Modification MEmber Functions
	void setName(std::string str)   { name = str; }
    void setAddr(std::string str)   { addr = str; }
    void setPhone(std::string str)  { phone = str; }
    void setSocial(std::string str) { social = str; }

	// Conctant Members
	std::string getName()   const { return name; }
	std::string getAddr()   const { return addr; }
	std::string getPhone()  const { return phone; }
	std::string getSocial() const { return social; }

	// Other Members
	void profileOut() const {
		std::cout << "***Account Profile***\n"
			      << "* 1. Social         *\n"
			      << "* 2. Phone          *\n"
			      << "* 3. Address        *\n"
			      << "* 4. Exit Account   *\n"
			      << "*********************\n";
	}

    std::ostream& print(std::ostream &os) const {
        return os << "\n**********Contact**********"
                  << "\nName: "    << getName()
                  << "\nPhone: "   << getPhone()
                  << "\nAddress: " << getAddr()
                  << "\nSocial: "  << getSocial() << "\n";
    }

private:
	// Data Members
	std::string name, addr, phone, social;
};

// Non-Member Functiond
std::ostream& operator<<(std::ostream &os, const Data &rhs) { return rhs.print(os); } 
bool operator==(const Data &lhs, const Data &rhs) { return(lhs.getName() == rhs.getName()); }
bool operator!=(const Data &lhs, const Data &rhs) { return !operator==(lhs, rhs); } 

#endif

