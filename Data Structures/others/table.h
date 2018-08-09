/*****************************************************************************************************
 * Ryan Lockman                                                                                      *
 * 101430670                                                                                         *
 * table.h                                                                                           *
 * Description: Hash Table and Hasher Prototypes, Nested HashException Prototypes/Implementations,   *
 *              and Bucket Struct Declaration.                                                       *
 *****************************************************************************************************/

// Macro
#ifndef TABLE_H
#define TABLE_H

// Headers
#include <cstdlib>
#include <stdexcept>
#include "record.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////
// Hasher Functor Class for Default Template Parameter
class Hasher {
public:
    // Member Constants
    static const int BASE = 8;

    // Constructors
    Hasher()  {} // default
    ~Hasher() {} // destructor

    // Modification Member Functions
    inline std::size_t hash(const int key, const std::size_t size);
    int radix_trans(const int key);

    // Overloaded Operators
    std::size_t operator()(const int key, std::size_t size) { return hash(key, size); }
};
///////////////////////////////////////////////////////////////////////////////////////////////////////

// Table Class
template<class T, class HashFunctor = Hasher> class Table {
public:
    // Typedefs
    typedef std::size_t size_type;
    typedef T value_type;
    typedef std::size_t (HashFunctor::*ptrFuncMemb)(int key, std::size_t size);
    
	// Member Constats
	static const std::size_t CAPACITY = 811;

	// Constructors
	explicit Table(ptrFuncMemb pfm = &HashFunctor::operator()); // default

	// Modification Member Functions
	void push(const T &entry, const int key);
	void pop(const int key);

	// Constant Member Functions
	bool is_present(const int key) const;
    bool is_empty() const { return used == 0; }
	void find(const int key, bool &found, T &result) const;

	size_type size() const { return used; }
    size_type getCollide() const { return collision; }

    void print() const;

//////////////////////////////////////////////////////////////////////////////////////////////////////
    // Nested Exception Class
    class HashException : public std::exception {
    public:
        // Constructors
        explicit HashException(const char *chr) : msg(chr) {}
        explicit HashException(std::string str) : msg(str) {}
        virtual ~HashException() throw() {} // destructor

        // Enums
        enum Error_Codes { KEY_BOUND_ERROR };

        // Constant Member Functions
        virtual const char* what() const throw() { return msg.c_str(); }

    protected:
        // Data Members
        std::string msg;
    };
/////////////////////////////////////////////////////////////////////////////////////////////////////

private:
	// Member Constants
	static const int NEVER_USED = -1, PREV_USED = -2;

/////////////////////////////////////////////////////////////////////////////////////////////////////
    // Bucket Struct
    struct Bucket {
        // Constructors
        explicit Bucket(const int key = -1, const T data = T()) : key(key), data(data) {} // default

        // Data Members
        int key;
        T data;
    };
/////////////////////////////////////////////////////////////////////////////////////////////////////

	// Data Members
	Bucket buckets[CAPACITY];
	size_type used, collision;
    ptrFuncMemb myHash;

	// Helper Functions	
    inline std::size_t next_index(const std::size_t index, const std::size_t count) const; // linear
    void find_index(const int key, bool &found, std::size_t &index) const;
	bool never_used(const std::size_t index) const;
	bool is_vacant(const std::size_t index) const;
};

#include "table.tem"
#endif

