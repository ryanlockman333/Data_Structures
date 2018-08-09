/*
Ryan
hashnode.h
Description: Hash Node, Iterators, and Linked List Tool-Kit template class prototypes.
*/

#ifndef HASHNODE_H
#define HASHNODE_H

// Headers
#include <cstdlib>
#include <string>

template<class Type> class Node {
public:
	// Typedefs
	typedef Type value_type;
	
	// Constructors
	Node(Node *linkIn = NULL, const Type &dataIn = Type(), const std::size_t keyIn = 0)
         : link(linkIn), data(dataIn), key(keyIn) {}
	
	// Get Member Functions
	Node* getLink()      { return link; }
	Type& getData()      { return data; }
    std::size_t getKey() { return key; }
	
	// Constant Member Functions
	const Node* getLink() const      { return link; }
	const Type&	getData() const      { return data; }
    const std::size_t getKey() const { return key; } 
	
	// Set Member Functions
	void setLink(Node *linkIn)           { link = linkIn; }
	void setData(const Type &dataIn)     { data = dataIn; }
    void setKey(const std::size_t keyIn) { key = keyIn; }

private:
	// Data Members
	Type data;
	Node *link;
    std::size_t key;
};

// node_iterator Class Prototypes
template<class Type>
class node_iterator : public std::iterator<std::forward_iterator_tag, Type> {
public:
	// Constructors
	node_iterator(Node<Type> *initial = NULL) : current(initial) {}
	
	// Overloaded Operators
	Type operator*() const { return current->getData(); }
	
    // ++Prefix
	node_iterator& operator++() { *this = current->getLink(); return *this; }
	// Postfix++
	const node_iterator operator++(int) { node_iterator oldValue = *this;
								          ++(*this); return oldValue; }
								  
	bool operator==(const node_iterator &rhs) const { return current == rhs.current; }
	bool operator!=(const node_iterator &rhs) const { return !(current == rhs.current); }
	
private:
	Node<Type> *current;
};

// const_node_iterator Class Prototypes
template<class Type>
class const_node_iterator : public std::iterator<std::forward_iterator_tag, const Type> {
public:
	// Constructors
	const_node_iterator(const Node<Type> *initial = NULL) : current(initial) {}
	
	// Overloaded Operators
	const Type operator*() const { return current->getData(); }
	
	// ++Prefix
	const_node_iterator& operator++() { *this = current->getLink(); return *this; }
	// Postfix++
	const const_node_iterator operator++(int) { const const_node_iterator oldValue = *this;
										        ++(*this); return oldValue; }
										  
	bool operator==(const const_node_iterator &rhs) const { return current == rhs.current; }
	bool operator!=(const const_node_iterator &rhs) const { return !(current == rhs.current); }
	
private:
	const Node<Type> *current;
};

// Linked-List Toolkit Prototypes
template<class Type>
size_t listLength(const Node<Type> *headIn);

template<class Type>
void listHeadInsert(Node<Type> *&headIn, const Type &entry, const std::size_t keyIn);

template<class Type>
void listInsert(Node<Type> *previous, const Type &entry, const std::size_t keyIn);

template<class NodePtr, class Type>
NodePtr listSearch(NodePtr headIn, const Type &target);

template<class NodePtr, class SizeType>
NodePtr listLocate(NodePtr headIn, SizeType pos);

template<class Type>
void listHeadRemove(Node<Type> *&head);

template<class Type>
void listRemove(Node<Type> *previous);

template<class Type>
void listClear(Node<Type> *&headIn);

template<class Type>
void listCopy(const Node<Type> *source, Node<Type> *&headIn, Node<Type> *&tail);

#include "hashnode.tem"
#endif

