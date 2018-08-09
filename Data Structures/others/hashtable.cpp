#include <iostream>
#include <string>
#include "HashChain.h"
#include "HashTable.h"

using namespace std;

HashTable::HashTable()
{
	hashTable[0] = NULL;
}

int HashTable::findHashOf(string key) const
{
	int stringValue;
	int i;
	for (i = 0; i < key.length(); i++) {	
	// traverse the string - the value of the string is (itself 
	// plus the ASCII value of the current letter) *
	// (its position in the string (starting at one))	
		stringValue += key[i] * (i + 1);		
	}
	// return the value % size of the table for the final position
	return (stringValue % TABLE_SIZE);
}

void HashTable::insert(string key, double value)
{
	int hash = findHashOf(key);					// find array position
	if (hashTable[hash] == NULL) {				// if there is nothing there
		HashChain *newChain = new HashChain(key, value);	// make new hash chain
		hashTable[hash] = newChain;				// point array position to the new chain	
	}
	else {
		HashChain *current = hashTable[hash];	// save object at current array position
		current->nextEntry(key, value);		// call the next entry function on the object for the new values
	}
}

void HashTable::setValue(string key, double newValue)	
{
	int hash = findHashOf(key);						// find the hash of the given variable
	HashChain *current = hashTable[hash];			// save the object at that location to a temporary one (if there is any)
	
	if (hashTable[hash] == NULL) {					// if there is nothing at that position		
		cout << key << " is undefined.\n";			// return an error message
	}
															
	else if (current->getKey(key) == true) {		// if that object contains the key
		current->setValueFor(key, newValue);		// set the new value
	}
}

void HashTable::print(string key) const			
{
	int hash = findHashOf(key);						// find the hash of the given variable
	HashChain *current = hashTable[hash];			// save object currently at this array position
	
	if (hashTable[hash] == NULL) {					// if nothing there
		cout << key << " is undefined.\n";			// print error, out of scope
	}
	
	else if (current->getKey(key) == true) {		// if that object contains the key, print the value
		cout << key << " is " << current->getValue(key) << endl;
	}
}

bool HashTable::keyExist(string key) const
{
	int hash = findHashOf(key);					// find the hash of the given variable
	HashChain *current = hashTable[hash];		// save object currently at this array position
	if (current->getKey(key) == true) {		// if that object contains the key, return true
		return true;
	}
	else return false;							// otherwise return false
}

double HashTable::findValueOf(string key) const
{
	int hash = findHashOf(key);					// find the hash 
	HashChain *current = hashTable[hash];		// save the object at this array position
	if (current->getKey(key) == true) {			// if that object contains the key
		return current->getValue(key);			// return the value of the variable
	}
	else {										// Otherwise return 0
		return 0;
	}
}

int hash::reHash(int key){
    return (key+1)%100;
}

void hash::Delete(){
    int key,i;
    bool isFound = false;
    cout<<"Enter the key to delete: ";
    cin>>key;
    for(i = 0; i < 40; i++){
        if(array[i] == key){
            isFound = true;
            break;
        }
    }
    if(isFound){
        array[i] = '*';
        cout<<"The key is deleted"<<endl;
    }else{
        cout<<"No key is Found!!";
    }
}
