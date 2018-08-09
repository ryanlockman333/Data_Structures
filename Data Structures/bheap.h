/*
 * Ryan Lockman
 * bheap.h
 * Description: binary heap class prototypes
 *
*/

/* 
// Pre/Post Comments
Heap();
    Post: Initializes the data by default.
Heap(const Heap &rhs);
    Post: Iitializes the data by copy.
~Heap();
    Post: Calls free() to destruct.
void operator=(const Heap &rhs);
    Pre:  Right Hand Sign must be of same type.
    Post: Copies RHS data into LHS data.
void push_back(const T &elem);
    Post: Pushes an element into the data structure.
T pop();
    Post: Pops the top element from the data structure and returns it.
void heapifyUp(int index);
    Post: Sorts the data at associated index up.
void heapifyDown(int index);
    Post: Sorts the data at associated index down.
int left(int parentIdx);
    Post: Returns parent's left child, otherwise returns -1 if none.
int right(int parentIdx);
    Post: Returns parent's right child, otherwise returns -1 if none.
int parent(int childIdx);
    Post: Returns child's parent, otherwise returns -1 if none(root).
T front() const;
    Post: Returns front element in data structure.
size_type size() const;
    Post: Returns the size of the data structure.
bool empty() const;
    Post: Returns true is empty, false otherwise.
void printHeap() const;
    Post: Prints the data structure out.
*/

#ifndef BHEAP_H
#define BHEAP_H

// Headers
#include <cstdlib>
#include <vector>

template<class T> class Heap {
public:
    // Typedefs
    typedef std::size_t size_type;
    typedef T value_type;
    typedef std::vector<T> Vector;

    // Constructors
    Heap() : heap(new Vector()), used(0) {} // default
    Heap(const Heap &rhs) : heap(rhs), used(rhs.size()) {} // copy
    ~Heap() { free(); } // destructor

    // Assignment Operator
    void operator=(const Heap &rhs) { heap = rhs; used = rhs.size(); }

    // Modififcation Member
    void push_back(const T &elem);
    T pop();
    void heapifyUp(int index);
    void heapifyDown(int index);
    int left(int parentIdx);
    int right(int parentIdx);
    int parent(int childIdx);

    // Const Members
    T front() const { return heap->front(); }
    size_type size() const { return used; }
    bool empty() const { return heap == NULL; }

    // Other Members
    void printHeap() const;

private:
    // Data Members
    Vector *heap;
    size_type used;

    // Helper Functions
    void free();
};

#include "bheap.tem"
#endif

