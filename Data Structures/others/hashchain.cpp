#include <iostream>
#include "HashChain.h"

using namespace std;

// Default constructor 
HashChain::HashChain()
{
	head = NULL;
}
// Overloaded constructor
HashChain::HashChain(string newKey, double newValue)
{
	node *newNode = new node;
	newEntry(newNode, newKey, newValue);
}

void HashChain::newEntry(node* newNode, string newKey, double newValue)
{
	newNode->key = newKey;			
	newNode->value = newValue;
	newNode->next = head;			// sets the new node to always point to the head unless otherwise specified
}

int HashChain::nextEntry(string newKey, double newValue)
{
	node *temp = head;
	node *newNode = new node; 
	newEntry(newNode, newKey, newValue);
	if (head->next == NULL) {			// if list consists of one element
		head->next = newNode;			// set head's pointer to new node and exit
		return 0;
	}
	while (temp->next != head) {		// so long as it's not the end of the list
		temp = temp->next;				// set temp to temp's next
	}
	temp->next = newNode;				// when done, set temp's next to the new item
	return 0;
}

void HashChain::setValueFor(string searchKey, double newValue)
{
	if (getKey(searchKey) == true) {				// if the variable exists in this list
		node *temp = head;							// create new node to hold temp	
		while (temp->key != searchKey && temp->next != head) {
			temp = temp->next;						// while the search key is not found and the next pointer is not the head
		}											// set the temp node to the next node
		temp->value = newValue;						// then set the temp node's value to the new value
		node *newTemp = temp;						// reiterate through the list with another temp variable
		while (newTemp != head) {
			newTemp = newTemp->next;
		}						
		head = newTemp;								// make sure head is set correctly
	}
	
	else {
		cout << searchKey << " is undefined.\n";	// If the search key is not found, return error message
	}
}

bool HashChain::getKey(string searchKey) const
{
	node *temp = head;								// create temporary variable to hold head
	while (temp->key != searchKey && temp->next != head) {	// while the search key is not found and the next pointer is not the head
		temp = temp->next;									// set the temp node to the next node
	}
	if (temp->key == searchKey) {					// double check if the current key is indeed the search key, if so return true
		return true;
	}
	else return false;								// otherwise return false
}

double HashChain::getValue(string searchKey) const
{
	node *temp = head;						
	while (temp->key != searchKey) {			// So long as the temp node's key is not the search key, set the temp node to the next node
		temp = temp->next;
	} 
	return temp->value;							// return the temp node's value
}
