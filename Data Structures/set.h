/********************************************************************************************************
 * Ryan Lockman                                                                                         *
 * set.h                                                                                                *
 * Description: Set template class prototypes.                                                          *
 *                                                                                                      *
 * Value Semantics: 	  The copy constructor and assignment operator can be used with the Set class.  *
 * Dynamic Memory Usage:  Assignment operator, copy constructor, copySet(private function), insert      *
 *					      and insert range use dynamic memory.                                          *
 * Compiler: Uses c++11				                                                                    *
 * 5/7/14			                                                                                    *
 ********************************************************************************************************/

// Macro
#ifndef SET_H
#define SET_H

// Headers
#include <cstdlib>
#include <iosfwd>
#include "nodeTem.h"

// Forward Declarations for operator<<
template<typename T> class Set;
template<typename T> std::ostream& operator<<(std::ostream&, const Set<T>&);

// Set Class
template<class T> class Set {
public:
// Typedefs
    typedef T value_type;
    typedef std::size_t size_type;
    typedef Set self_type;

    // Node Iterator
    typedef node_iterator<T> iterator;
    typedef typename iterator::reference reference;
    typedef typename iterator::pointer pointer;
    typedef typename iterator::iterator_category iterator_category;
    typedef typename iterator::difference_type difference_type;

    // Const Node Iterator
    typedef const_node_iterator<T> const_iterator;
    typedef typename const_iterator::const_reference const_reference;
    typedef typename const_iterator::const_pointer const_pointer;
    typedef typename const_iterator::iterator_category const_iterator_category;
    typedef typename const_iterator::difference_type const_difference_type;

// Constructors
	explicit Set(Node<T> *head = nullptr) : head(head), used(0) {}                         // default
    // Post: Initializes data members
	Set(const self_type &st) : head(nullptr), used(0) { copySet(st); }                     // copy
    // Post: Initializes this Set to right hand sign
    template<typename InputIterator> Set(InputIterator b, InputIterator e);                // range
    // Post: Initializes this Set in ranger of iterator [b,e-1)
    Set(self_type &&st) : head(st.head), used(st.used) { st.head = nullptr; st.used = 0; } // move
    // Post: 
	~Set() { clear(); }                                                                    // destuctor
    // Post: Frees all data members, clears Set

// Assignment Operator Overload
	void operator=(const Set &rhs) { if(this != &rhs) copySet(rhs); }
    // Post: Copies rhs to this Set
	
// Modification Member Functions
	void insert(const T &entry);
	// Post: A new entry is inserted into the Set
    template<typename Iterator> void insert_range(Iterator b, Iterator e);
    // Post: Inserts the specified data range of Iterator [b, e-1)
	void erase(const T &target);
	// Post: All copies of target are removed from Set
	void clear();
    // Post: Clears all Sets elements and reinitializes members
    
    //T* find(const T &target);
    // Post: Returns target if found, nullptr otherwise
    iterator find(const T &target);
    // Post: Returns target iterator if found, end() otherwise
	
// Constant Member Functions
	size_type size() const { return used; }
    // Post: Returns total number of entries
	bool empty()     const { return head == nullptr; }
    // Post: Returns true if empty, false otherwise

	bool contains(const T &target) const;
	// Post: Returns true if the Set contains the target item, false otherwise
	T* grab() const;
    // Post: Return value is a randomly selected element from the Set, nullptr otherwise
    const_iterator find(const T &target) const;
    // Post: Returns target const_interator if found, end() otherwise
	
// Other Member Functions
	void display() const;
    // Post: Prints contents of Set
	
// Friend Overloads
    friend std::ostream& operator<< <T>(std::ostream& os, const Set<T> &rhs);
    // Post: Prints the data contents of the list via the ostream operator.

// Iterator Functions
	iterator begin()              { return iterator(head); }
    // Post: Returns iterator to the beginning of the Set
	iterator end()                { return iterator(); }
    // Post: Returns iterator one past the end of the Set
	const_iterator begin()  const { return const_iterator(head); }
    // Post: Returns const_iterator to the beginning of the Set
	const_iterator end()    const { return const_iterator(); }
    // Post: Returns const_iterator one past the end of the Set
    const_iterator cbegin() const { return const_iterator(head); }
    // Post: Returns const_iterator to the beginning of the Set (for auto)
	const_iterator cend()   const { return const_iterator(); }
    // Post: Returns const_iterator one past the end of the Set (for auto)
	
private:
// Private Data Members
	Node<T>  *head;
	size_type used;
	
// Helper Member Functions
	void copySet(const self_type &rhs);
};

// Non-Member Functions
    template<class set_T>
    void setUnion(const set_T &s1, const set_T &s2, set_T &result);
    // Post: Result Set is the union of s1 and s2
    template<class set_T>
    void setIntersection(const set_T &s1, const set_T &s2, set_T &result);
    // Post: Result Set is the intersection of s1 and s2
    template<class set_T>
    void setDifference(const set_T &s1, const set_T &s2, set_T &result);
    // Post:  Result Set is the difference of s1 and s2
    template <class set_T>
    void setSymmetricDiff(const set_T &s1, const set_T &s2, set_T &result);
    // Post: Result set is the symmetric difference of s1 and s2

    // Overloaded Operators
    template<class set_T>
    set_T operator|(const set_T &lhs, const set_T &rhs); // Union(OR analogous)
    // Post: Returned Set is the union of lhs and rhs
    template<class set_T>
    set_T operator&(const set_T &lhs, const set_T &rhs); // Intersection(AND analogous)
    // Post: Returned Set is the intersection of lhs and rhs
    template<class set_T>
    set_T operator-(const set_T &lhs, const set_T &rhs); // Difference(NOT analogous)
    // Post:  Returned Set is the difference of lhs and rhs
    template<class set_T>
    set_T operator^(const set_T &lhs, const set_T &rhs); // Symmetric Difference(XOR analogous)
    // Post: Returned set is the symmetric difference of lhs and rhs

    template<class set_T>
    bool operator==(const set_T &lhs, const set_T &rhs);
    // Post: Returns true if Sets are equal, false otherwise
    template<class set_T>
    bool operator!=(const set_T &lhs, const set_T &rhs) { return !operator==(lhs, rhs); }
    // Post Returns true if Sets are not equal, false otherwise

#include "set.tem"
#endif

