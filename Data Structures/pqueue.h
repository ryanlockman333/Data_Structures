/* 
 * Ryan Lockman
 * priorQueue.h
 * Description: priority queue class prototypes
 *
*/

/* 
// Pre/Post Conditions
PriorQueue();
    Post: Initializes the data structure by default.
PriorQueue(const PriorQueue &rhs);
    Post: Initializes the data structure by copy.
~PriorQueue();
    Post: Calls free() to destruct the data.
void operator=(const PriorQueue &rhs);
    Pre:  Right Hand Sign must be of same type.
    Post: Copies the data from RHS to LHS.
void push_back(const T &elem);
    Post: Pushes back an element into the data structure.
void pop();
    Post: Pops the top element from the data struture.
T top() const;
    Post: Returns the top element of the data structure.
size_type size() const;
    Post: Returns the size of the data structure.
bool empty() const;
    Post: Returns true if empty, otherwise false.
void printPQueue() const;
    Post: Prints the priority queue.

// Semantics
Default container is a Heap, if chosen to use own data class be sure
it has own member functions: front(), push_back(), and pop().
*/

#ifndef PQUEUE_H
#define PQUEUE_H

// Headers
#include <cstdlib>
#include "bheap.h"

template<class T, class Container = Heap<T> > class PriorQueue {
public:
    // Typedefs
    typedef std::size_t size_type;
    typedef T value_type;

    // Constructors
    PriorQueue() : data(new Container()), used(0) {} // default
    PriorQueue(const PriorQueue &rhs) : data(rhs), used(rhs.size) {} // copy
    ~PriorQueue() { free(); } // destructor

    // Assignment Operator
    void operator=(const PriorQueue &rhs) { data = rhs; used = rhs.size(); }

    // Modififcation Member
    void push_back(const T &elem);
    void pop();
    
    // Const Members
    T top() const { return data->front(); }
    size_type size() const { return used; }
    bool empty() const { return data == NULL; }

    // Other Members
    void printPQueue() const { data->printHeap(); }

private:
    // Data Members
    Container *data;
    size_type used;

    // Helper Functions
    void free();
};

#include "pqueue.tem"
#endif

