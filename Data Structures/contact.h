/*
Ryan Lockman
contact.h
Desription: Contact class prototypes.
*/

#ifndef CONTACT_H
#define CONTACT_H

// Headers
#include <string>
#include <fstream>
#include "field.h"

class Contact {
public:
	// Constructors
	Contact() : firstName("Unknown"), lastName("Unknown"), street("Unknown"), city("Unknown"),
                state("Unknown"),     zip("Unknown"),      phone("Unknown"),  birth("Unknown"), 
                email("Unknown"),     pin(),               pass() { }

	Contact(std::string fName,   std::string lName, std::string stIn,    std::string cityIn, 
            std::string stateIn, std::string zipIn, std::string phoneIn, std::string birthIn, 
            std::string emailIn, std::string pinIn, std::string passIn) 
          : firstName(fName),    lastName(lName), street(stIn),   city(cityIn), state(stateIn), zip(zipIn),
            phone(phoneIn),      birth(birthIn),  email(emailIn), pin(pinIn),   pass(passIn) { } 

	// Set Member Fuctions
    void setFirstName(std::string fName)    { firstName = fName; }
	void setLastName (std::string lName)    { lastName  = lName; }
    void setStreet   (std::string streetIn) { street = streetIn; }
	void setCity     (std::string cityIn)   { city = cityIn; }
	void setState    (std::string stateIn)  { state = stateIn; }
	void setZip      (std::string zipIn)    { zip = zipIn; }
	void setPhone    (std::string phoneIn)  { phone = phoneIn; }
	void setBirthday (std::string birthIn)  { birth = birthIn; }
	void setEmail    (std::string emailIn)  { email = emailIn; }
    void setPin      (std::string pinIn)    { pin = pinIn; }
    void setPass     (std::string passIn)   { pass = passIn; }

	// Get Member Functions
    std::string getFirstName() const { return firstName; }
	std::string getLastName()  const { return lastName; }
    std::string getStreet()    const { return street; }
	std::string getCity()      const { return city; }
	std::string getState()     const { return state; }
	std::string getZip()       const { return zip; }
	std::string getPhone()	   const { return phone; }
	std::string getBirthday()  const { return birth; }
	std::string getEmail()     const { return email; }
    std::string getPin()       const { return pin; }
    std::string getPass()      const { return pass; }

    // Other Member Functions
    std::string profileOut() const;

    // Relational Opertors
	friend bool operator==(const Contact &lhs, const Contact &rhs) { return lhs.pin == rhs.pin; }
	friend bool operator!=(const Contact &lhs, const Contact &rhs) { return !operator==(lhs, rhs); }
	friend bool operator< (const Contact &lhs, const Contact &rhs); // actual parameter
	friend bool operator> (const Contact &lhs, const Contact &rhs) { return  operator< (rhs, lhs); }
	friend bool operator<=(const Contact &lhs, const Contact &rhs) { return !operator> (lhs, rhs); }
	friend bool operator>=(const Contact &lhs, const Contact &rhs) { return !operator< (lhs, rhs); }

	// Stream Operators
	friend std::istream&  operator>>(std::istream &is, Contact &rhs);
	friend std::ifstream& operator>>(std::ifstream &ifs, Contact &rhs);
	friend std::ostream&  operator<<(std::ostream &os, const Contact &rhs);
	friend std::ofstream& operator<<(std::ofstream &ofs, const Contact &rhs); 

private:
	// Data Members
	std::string firstName, lastName, street, city, state, zip, phone, birth, email,
                pin, pass;
}; 

#endif

