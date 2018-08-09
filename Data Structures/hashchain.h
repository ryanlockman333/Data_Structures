/*
Ryan
HashChain.h Clas Prototypes
*/

// Macros
#ifndef HASHCHAIN_H
#define HASHCHAIN_H

// Headers
#include <cstdlib>
#include "set.h"

// Class
template<class Type>
class HashChain {
public:
	// Member Constats
	static const std::size_t CAPACITY = 10007;

	// Typedefs
	typedef std::size_t size_type;

    // Constructors
    HashChain() : used(0), collision(0), usedKeys{0}, usedKeyIndex(0) {} // default
    HashChain(const HashChain &rhs) {} // copy
    ~HashChain() { free(); } // destructor

    // Overloaded Operatos
    void operator=(const HashChain &rhs);

    // Modification MemberFunctions
    void insertRecord(const std::size_t key, const Type &entry);
    void removeRecord(const std::size_t key, Type &target);
    void resetCollide() { collision = 0; }

    // Constant Member Functions
	bool is_empty_chain(const std::size_t index) const { return data[index].isEmpty(); }
    bool is_empty_hashchain() const { return used == 0; }
    bool find(const std::size_t key, const Type &target, Type &grab) const;
    std::size_t size() const { return used; }
    std::size_t getCollisions() const { return collision; }

    // Check Indexes Left 
    unsigned checkIndexLeft() const;
    unsigned checkIndexUsed() const;

    // Other Member Functions
    void printChain(std::size_t index) const;
    void printHashChain() const;

private:
	// Private Member Constants
	static const size_t BASE = 2;  
    
    // Member Variables
 	Set<Type> data[CAPACITY];
	std::size_t used, collision, usedKeys[CAPACITY], usedKeyIndex;

    // Helper Functions
  	inline std::size_t hash(const std::size_t key) const; // Radix Transform
    std::size_t radix_trans(std::size_t key, const unsigned base) const;
    void copyChain(const std::size_t index, const HashChain &rs);
    void copyHashChain(const HashChain &rhs);
    void freeChain(const std::size_t index);
    void free();
};

#include "hashchain.tem"
#endif

