/*
 * Ryan Lockman
 * 101430670
 * field.h 
 * Description: Field Class Prototypes
*/

// Macro
#ifndef FIELD_H
#define FIELD_H

// Headers
#include <iostream>
#include <fstream>
#include <string>

// Class
class Field: public std::string {
public:
	// Constructors
	Field() : std::string() {} // default
	Field(const std::string str) : std::string(str) {}
	Field(const char *chrStr) : std::string(chrStr) {}

	// Stream Operators
	friend std::istream&  operator>>(std::istream &is, Field &fld);
	friend std::ifstream& operator>>(std::ifstream &ifs, Field &fld);
};

#endif

