/*****************************************************************************************************
 * Ryan Lockman                                                                                      *
 * 101430670                                                                                         *
 * table.h                                                                                           *
 * Description: Hash Table and Hasher Prototypes, Nested HashException Prototypes/Implementations,   *
 *              and Bucket Struct Declaration.                                                       *
 * 3/18/14                                                                                           *
 *****************************************************************************************************/

// Macro
#ifndef TABLE_H
#define TABLE_H

// Headers
#include <cstdlib>
#include <stdexcept>

///////////////////////////////////////////////////////////////////////////////////////////////////////
// Hasher Functor Class for Default Template Parameter
class Hasher {
public:
// Modification Member Functions
    inline std::size_t hash(const std::string str);
    // Post: hash returns the computed key.

// Overloaded Operators
    std::size_t operator()(const std::string str) { return hash(str); }
    // Post: operator() returns hash function, enabling functor.
};
///////////////////////////////////////////////////////////////////////////////////////////////////////

// Table Class
template<class T, class HashFunctor = Hasher, std::size_t CAP = 811> class Table {
public:
// Typedefs
    typedef std::size_t size_type;
    typedef T value_type;
    typedef std::string key_type;
    typedef Table<T, HashFunctor, CAP> self_type;
    typedef std::size_t (HashFunctor::*ptrFuncMemb)(const std::string str);
    
// Member Constats
	static const std::size_t CAPACITY = CAP;

// Constructors
	explicit Table(const ptrFuncMemb pfm = &HashFunctor::operator()); // default
    // Pre:  ptrFuncMember must be a member to a functor class.
    // Post: Sets myHash data member with correct pointer to member function.

// Modification Member Functions
	void push(const T &entry, const std::string str);
    // Pre:  Table size must be < CAPACITY.
    // Post: entry is pushed into table.
	void pop(const std::string str);
    // Pre:  Table size must be > 1.
    // Post: Data at index hashed form str is popped out.
    T& data_at_index(const std::size_t index) { return buckets[index].data; }
    // Post: Returns data at specified index.

// Constant Member Functions
	bool is_present(const std::string str) const;
    // Post: Returns true if str(key) is in the table, false otherwise.
    bool is_vacant(const std::size_t index) const { return buckets[index].is_empty(); }
    // Post: Returns true if specified index in table is vacant, false otherwise.
    bool is_empty() const { return size() == 0; }
    // Post: Returns true if table is empty, false otherwise.

    const T& data_at_index(const std::size_t index) const { return buckets[index].getData(); }
    // Post: Returns constant data at specified index.
	bool find(const std::string str, T &result) const;
    // Post: Returns true if hashed str is in the table and sets result to that data, otherwise
    //       returns false and result is empty.

	size_type size() const { return used; }
    // Post: Returns number of entries in table.
    size_type getCollide() const { return collision; }
    // Post: Returns total collisions.

    unsigned checkIndexLeft() const;
    // Post: Returns table indexes unused.
    unsigned checkIndexUsed() const;
    // Post: Returns table indexes used.

    void display() const;
    // Post: Displays hash table.

//////////////////////////////////////////////////////////////////////////////////////////////////////
// Nested Exception Class
    class HashException : public std::exception {
    public:
    // Constructors
        explicit HashException(const char *chr) : msg(chr) {}
        // Post: Constructs data member based on char.
        explicit HashException(const std::string str) : msg(str) {}
        // Post: Constructs data member based on std::string.
        virtual ~HashException() throw() {} // destructor for derived class

    // Constant Member Functions
        virtual const char* what() const throw() { return msg.c_str(); }
        // Post: Returns error message.

    protected:
        // Data Members
        std::string msg;
    };
/////////////////////////////////////////////////////////////////////////////////////////////////////

private:
// Private Member Constants
	static const std::string NEVER_USED, PREV_USED;

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Bucket Struct
    struct Bucket {
    // Constructors
        explicit Bucket(const std::string str = NEVER_USED, const T data = T())
            : key(str), data(data) {} // default

    // Constant Member Functions
        const std::string& getKey() const { return key; }
        const T& getData() const { return data; }
        bool is_empty() const { return getKey() == NEVER_USED || getKey() == PREV_USED; }

    // Data Members
        key_type   key;
        value_type data;
    };
/////////////////////////////////////////////////////////////////////////////////////////////////////

// Data Members
	Bucket buckets[CAPACITY];
	size_type used, collision;
    ptrFuncMemb myHash;

// Helper Functions	
    inline std::size_t next_index(const std::size_t index) const; // linear probing
    bool find_index(const std::string str, std::size_t &index) const;
	bool never_used(const std::size_t index) const { return buckets[index].getKey() == NEVER_USED; }
    bool prev_used(const std::size_t index)  const { return buckets[index].getKey() == PREV_USED; }
};

#include "table.tem"
#endif

