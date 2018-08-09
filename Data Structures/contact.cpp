/*
Ryan Lockman
contact.h
Desription: Contact class prodefinitions.
*/

// Headers
#include <iostream>
#include "myfuncts.h"
#include "contact.h"

// Other Member Functions
std::string Contact::profileOut() const {
    return ("\n**********MENU**********"
            "\n* 1. Name              *"
            "\n* 2. Address           *"
            "\n* 3. Phone             *"
            "\n* 4. Email             *"
            "\n* 5. BirthDay          *"
            "\n* 6. Exit Account      *"
            "\n************************");
}

// Relational Opertors
bool operator<(const Contact &lhs, const Contact &rhs) {
	return( (strToUpper(lhs.getLastName() + lhs.getFirstName())) < 
            (strToUpper(rhs.getLastName() + rhs.getFirstName())) );
}

// Stream Operators
std::istream& operator>>(std::istream &is, Contact &rhs) {
	Field fld;

	// add

	std::cout << "Please enter Phone Number:   ";
	is >> fld;
	rhs.setPhone(fld);
	std::cout << "Please enter Birthday:       ";
	is >> fld;
	rhs.setBirthday(fld);
	std::cout << "Please enter E-mail Address: ";
	is >> fld;
	rhs.setEmail(fld);
    std::cout << "Please enter Pin number: ";
    is >> fld;
    rhs.setPin(fld);

	return is;
}

std::ifstream& operator>>(std::ifstream &ifs, Contact &rhs) {
	Field   fld;

    ifs >> fld;
    rhs.setPin(fld);

	ifs >> fld;
	rhs.setFirstName(fld);
    ifs >> fld;
    rhs.setLastName(fld);
	ifs >> fld;
    rhs.setStreet(fld);
    ifs >> fld;
    rhs.setCity(fld);
    ifs >> fld;
    rhs.setState(fld);
    ifs >> fld;
    rhs.setZip(fld);
	ifs >> fld;
	rhs.setPhone(fld);
	ifs >> fld;
	rhs.setEmail(fld);
	ifs >> fld;
	rhs.setBirthday(fld);

	return ifs;
}

std::ostream& operator<<(std::ostream &os, const Contact &rhs) {
    os << "*****Contact*****\n"
       << rhs.getPin()       << "\n"
       << rhs.getFirstName() << "\n"
       << rhs.getLastName()  << "\n"
	   << rhs.getStreet()    << "\n"
       << rhs.getCity()      << "\n"
       << rhs.getState()     << "\n"
       << rhs.getZip()       << "\n"
	   << rhs.getPhone()     << "\n" 
       << rhs.getEmail()     << "\n"
	   << rhs.getBirthday()  << "\n\n"; 
	return os;
}

std::ofstream& operator<<(std::ofstream &ofs, const Contact &rhs) {
	ofs << rhs.getPin()       << ","
        << rhs.getFirstName() << ","
        << rhs.getLastName()  << ","
	    << rhs.getStreet()    << ","
        << rhs.getCity()      << ","
        << rhs.getState()     << ","
        << rhs.getZip()       << ","
	    << rhs.getPhone()     << "," 
        << rhs.getEmail()     << ","
		<< rhs.getBirthday()  << ",\n";
	return ofs;
}

