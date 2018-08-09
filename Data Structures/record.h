/*
 * Ryan Lockman
 * 101430670
 * record.h
 * Description: Record Class Prototypes
 * 3/17/14
 *
*/

// Macro
#ifndef RECORD_H
#define RECORD_H

// Headers
#include <iostream>
#include <string>
#include <vector>

// Global Helper Function
std::string strToUpper(const std::string str) {
    std::string ans = str;
	for(std::size_t i = 0; i < str.length(); ++i)
		ans[i] = toupper(str[i]);
	return ans;
}
// Post: Returns uppercased str.

// Record Class
class Record {
public:
    // Typedefs
    typedef float value_type;
    typedef std::vector<value_type> Vector;

	// Constructors
	Record(const std::string name = std::string(), const Vector &monthHours = Vector())
        : name(name), monthHours(monthHours), monthDues() {} // default
    // Post: Constructs data members of Record.

	// Modification Member Functions
	void setName(const std::string str) { name = str; }
    // Post: Sets name member of Record.
    void setmonthHours(const Vector &monthHoursIn) { monthHours = monthHoursIn; }
    // Post: Sets month hours data structure of Record.

    // Get Member Functions
    std::string getName()   { return name; }
    // Post: Returns name.
    Vector& getMonthHours() { return monthHours; }
    // Post: Returns month hours.
    Vector& getMonthDues()  { return monthDues; }
    // Post: Returns Month dues.

    // Constant Member Functions
	const std::string getName()   const { return name; }
    // Post: Returns constant Name.
    const Vector& getMonthHours() const { return monthHours; }
    // Post: Returns constant MonthHours.
    const Vector& getMonthDues()  const { return monthDues; }
    // Post: Returns constant MonthDues.

    // Relational Opertors
	friend bool operator==(const Record &lhs, const Record &rhs) { return strToUpper(lhs.getName()) == strToUpper(rhs.getName()); }
    // Post: Actual Call, Returns true if LHS name == RHS name, false otherwise.
	friend bool operator!=(const Record &lhs, const Record &rhs) { return !operator==(lhs, rhs); }
    // Post: Calls operator==
	friend bool operator< (const Record &lhs, const Record &rhs) { return strToUpper(lhs.getName())  < strToUpper(rhs.getName()); }
    // Post: Actual Call, Returns true if LHS name < RHS name, false otherwise.
	friend bool operator> (const Record &lhs, const Record &rhs) { return  operator< (rhs, lhs); }
    // Post: Calls operator<
	friend bool operator<=(const Record &lhs, const Record &rhs) { return !operator> (lhs, rhs); }
    // Post: Calls operator>
	friend bool operator>=(const Record &lhs, const Record &rhs) { return !operator< (lhs, rhs); }
    // Post: Calls operator<

private:
	// Record Members
	std::string name;
    Vector monthHours, monthDues;
};

#endif

