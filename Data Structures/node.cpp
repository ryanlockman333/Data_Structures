/*
Ryan Lockman: 101430670
CSCI 2421:001 Fall 2013
node.cpp
Description: Node class definitions.
*/

// Headers
#include <cassert>
#include "node.h"

// Linked-List Toolkit Functions
size_t listLength(const Node *headIn) {
	size_t answer = 0;
	
	for(const Node *cursor = headIn; cursor != NULL; cursor = cursor->getLink())
		++answer;
		
	return answer;
}

void listHeadInsert(Node *&headIn, const Node::value_type &entry) {
	headIn = new Node(entry, headIn);
}

void listInsert(Node *previous, const Node::value_type &entry) {
	previous->setLink(new Node(entry, previous->getLink()));
}

Node* listSearch(Node *headIn, const Node::value_type &target) {
	for(Node *cursor = headIn; cursor != NULL; cursor = cursor->getLink())
		if(target == cursor->getData())
			return cursor;
	return NULL;
}

const Node* listSearch(const Node *headIn, const Node::value_type &target) {
	for(const Node *cursor = headIn; cursor != NULL; cursor = cursor->getLink())
		if(target == cursor->getData())
			return cursor;
	return NULL;
}

Node* listLocate(Node *headIn, const size_t pos) {
	Node *cursor = headIn;
	
	assert(pos > 0);
	for(int i = 1; (i < pos) && (cursor != NULL); ++i)
		cursor = cursor->getLink();
		
	return cursor;
}

const Node* listLocate(const Node *headIn, const size_t pos) {
	const Node *cursor = headIn;
	
	assert(pos > 0);
	for(int i = 1; (i < pos) && (cursor != NULL); ++i)
		cursor = cursor->getLink();
		
	return cursor;
}

void listHeadRemove(Node *&headIn) {
	Node *remove = headIn;
	
	headIn = headIn->getLink();
	delete remove;
}

void listRemove(Node *previous) {
	Node *remove = previous->getLink();
	
	previous->setLink(remove->getLink());
	delete remove;
}

bool is_empty(const Node *headIn) {
    return headIn == NULL;
}

void listClear(Node *&headIn) {
	while(headIn != NULL)
		listHeadRemove(headIn);
}

void listCopy(const Node *source, Node *&headIn, Node *&tailIn) {
	headIn = NULL;
	tailIn = NULL;
	
	if(source == NULL)
		return;
		
	listHeadInsert(headIn, source->getData());
	tailIn = headIn;
	
	source = source->getLink();
	while(source != NULL) {
		listInsert(tailIn, source->getData());
		tailIn = tailIn->getLink();
		source = source->getLink();
	}
}
