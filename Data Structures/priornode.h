/*
 * Ryan
 * weightnode.h
 * Description: weightity Queue Node class protoTs.
*/

#ifndef PRIORNODE_H
#define PRIORNODE_H

// Headers
#include <cstdlib>
#include <fstream>

template<typename T> class Node {
public:
	// Constructors
	Node(const T &val1 = T(), const T &val2 = T(), const std::size_t weightIn = 0)
         : u(val1), v(val2), weight(weightIn) {}

	// Get Member Functions
    T& getU() { return u; }
    T& getV() { return v; }
    std::size_t getweight() { return weight; }
	
	// Constant Member Functions
	const T& getU() const { return u; }
    const T& getV() const { return v; }
    const std::size_t getWeight() const { return weight; } 
	
	// Set Member Functions
	void setData(const T &val1, const T &val2) { u = val1; v = val2; }
    void setweight(const std::size_t weightIn) { weight = weightIn; }

    // Relational Opertors
	friend bool operator==(const Node &lhs, const Node &rhs) { return lhs.getWeight() == rhs.getWeight(); }
	friend bool operator!=(const Node &lhs, const Node &rhs) { return !operator==(lhs, rhs); }
	friend bool operator< (const Node &lhs, const Node &rhs) { return lhs.getWeight() <  rhs.getWeight(); }
	friend bool operator> (const Node &lhs, const Node &rhs) { return  operator< (rhs, lhs); }
	friend bool operator<=(const Node &lhs, const Node &rhs) { return !operator> (lhs, rhs); }
	friend bool operator>=(const Node &lhs, const Node &rhs) { return !operator< (lhs, rhs); }

    // Stream Operators
    template<typename U>
	friend std::ostream& operator<<(std::ostream &os, const Node<U> &rhs);

private:
	// Data Members
    T u;
    T v;
    std::size_t weight;
};

#include "priornode.tem"
#endif

