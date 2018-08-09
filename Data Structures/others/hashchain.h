#include <iostream>

using namespace std;

#ifndef HASHCHAIN_H
#define HASHCHAIN_H

class HashChain {
private:

	struct node {
		string key;
		int value;
		node *next;
	};

	node *head; 
	
public:

	//Default constructor
	HashChain();
	
	//Overloaded constructor
	HashChain(string newKey, double newValue);

	/*
	 *	newEntry() - assigns new values to a given node and sets it's pointer to the head
	 * @param newNode - the new node
	 * @param newKey - the variable name
	 * @param newValue - the variable's value
	 */
	void newEntry(node *newNode, string newKey, double newValue);

	/* 
	 *	nextEntry() - inserts a new node into the list
	 * @param newKey - the variable name
	 * @param newValue - the variable's value
	 * @return - 0 when insertion is completed
	 */
	int nextEntry(string newKey, double newValue);
	
	/*
	 *  setValueFor() - sets a new value for an existing variable
	 * @param searchKey - the variable who's value is to be changed
	 * @param newValue - the new value
	 */
	void setValueFor(string searchKey, double newValue);
	
	/*
	 *  getKey() - determined whether a variable exists within the current list
	 * @param searchKey - the variable to search for
	 * @return - true if the key is found, otherwise false
	 */
	bool getKey(string searchKey) const;

	/*
	 *  getValue() - returns the value of a given key
	 * @param searchKey - the variable who's value is to be returned
	 * @return - the value
	 */
	double getValue(string searchKey) const;
};

#endif
