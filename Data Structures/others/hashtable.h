// Headers
#include <iostream>
#include "HashChain.h"

using namespace std;

#ifndef HASHTABLE_H
#define HASHTABLE_H

class HashTable {
public:
	//Default constructor
	HashTable();

	/*
	 *  findHashOf - find the hashed value of a string
	 * @param key - the string to be hashed
	 * @return - the hash location
	 */
	int findHashOf(string key) const;
	
	/*
	 *  insert() - inserts a new variable and it's associated value into the table
	 * @param key - the variable
	 * @param value - the value of the variable
	 */
	void insert(string key, double value);
	
	/*
	 *	setValue() - assigns a new value to an existing variable in the table
	 * @param key - the existing variable
	 * @param newValue - the new value
	 */
	void setValue(string key, double newValue);
	
	/* 
	 *  print() - prints the value of an existing variable in the table
	 * @param key - the key who's value is to be printed
	 */
	void print(string key) const; 
	
	/*
	 *  keyExist() - determines whether a variable exists within the table
	 * @param key - the key to search for
	 * @return - true if the variable exists, false otherwise
	 */
	bool keyExist(string key) const;
	
	/*
	 *  findValueOf() - finds the value of a given variable in the table
	 * @param key - the variable 
	 * @return - the value if the variable exists, otherwise 0
	 */
	double findValueOf(string key) const;
	
	int reHash(int );
	
	void Delete();
private:

		static int const TABLE_SIZE = 97;
		HashChain *hashTable[TABLE_SIZE];
};

#endif
