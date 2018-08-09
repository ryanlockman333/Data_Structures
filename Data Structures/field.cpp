/*
 * Ryan Lockman
 * 101430670
 * field.h 
 * Description: Field Class Implementations
*/

// Headers
#include "field.h"

// Stream Operators
std::istream& operator>>(std::istream &is, Field &fld) {
	if(is.peek() == '\n')
		is.ignore();
	std::getline(is, fld, ' ');
	return is;
}

std::ifstream& operator>>(std::ifstream &ifs, Field &fld) {
	std::getline(ifs, fld, ' ');
	if(ifs.peek() == '\n')
		ifs.ignore();
	return ifs;
}

