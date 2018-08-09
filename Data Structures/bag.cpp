/*
Ryan Lockman: 101430670
CSCI 2421:001 Fall 2013
bag.cpp
Description: Bag class definitions.
*/

// Headers
#include <iostream>
#include <cassert>
#include <algorithm>
#include "bag.h"
	
// Assignment Operator
Bag& Bag::operator=(const Bag &otherBag) {
	if(this != &otherBag)
		copyBag(otherBag);
	return *this;
}
	
// Modification Member Functions
void Bag::insert(const value_type &entry) {
	listHeadInsert(head, entry);
	++used;
}

void Bag::erase(const value_type &target) {
	Node *targetNode = listSearch(head, target);
	
	while(targetNode != NULL) {
		targetNode->setData(head->getData());
		targetNode = targetNode->getLink();
		targetNode = listSearch(targetNode, target);
		listHeadRemove(head);
		--used;
	}
}

bool Bag::eraseOne(const value_type &target) {
	size_type idx = 0;
	
	while((idx < size()) && (data[used] != target))
		++idx;
		
	if(idx == used)
		return false;
		
	--used;
	data[idx] = data[used];
	return true;
}

// Constant Member Functions
Bag::value_type Bag::grab() const {
	assert(size() > 0);
	const Node *cursor = NULL;
	
	size_type pos = (rand() % size()) + 1;
	cursor        = listLocate(head, pos);
	
	return cursor->getData();
}

Bag::size_type Bag::count(const value_type &target) const {
	size_type ans = 0;
	
	for(size_type i = 0; i < size(); ++i)
		if(target == data[i];
			++ans;
	return ans;
}

// Other Member Functions
void Bag::display() const {	
	std::cout << std::endl;
	for(Node *cursor = head; cursor != NULL; cursor = cursor->getLink())
		std::cout << cursor->getData() << " ";
}
	
// Operator Overloads
void Bag::operator+=(const Bag &rhs) {
	copy(rhs.data, rhs.data + rhs.used, data + used);
	used += rhs.used;
}
	
// Private Member Functions
void Bag::free() {
	listClear(head);
	head = NULL;
	used = 0;
}

void Bag::copyBag(const Bag &otherBag) {
	Node *tail = NULL;
	
	free();
	listCopy(otherBag.head, head, tail);
	used = otherBag.used;
}
