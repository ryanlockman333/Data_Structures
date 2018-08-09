/*
     -------------------------------------------------------------------
    |                                                                   |
    |    HeapTree Class                                                 |
    |    ===========================================================    |
    |    This HeapTree Class has been implemented with templates.       |
    |                                                                   |
    |    To use the HeapSort that is built into the class, two          |
    |    separate steps must be taken. The first is the constructor:    |
    |                                                                   |
    |        HeapTree<Type> HeapName(Array, Num, MaxNum);               |
    |                                                                   |
    |    'Type' is the data type of the Array elements, 'Array' is a    |
    |    standard C++ array to be sorted and 'Num' is the number of     |
    |    elements in the array. MaxNum sets the limit on the number     |
    |    of data nodes that the Heap can have. If you are only using    |
    |    the heap for sorting, you can set MaxNum to Num. (However,     |
    |    MaxNum should not be set less than Num).                       |
    |                                                                   |
    |    When the constructor is called, the Heap *copies* the Array.   |
    |    Thus, neither the Array variable nor what it points to will    |
    |    be modified.                                                   |
    |                                                                   |
    |    The second step is to call the actual sort:                    |
    |                                                                   |
    |        NewArray *Sort();                                          |
    |                                                                   |
    |    This sort will return a pointer to another array, which is     |
    |    the sorted array. Any modifications done to NewArray or its    |
    |    contents will not affect the heap.                             |
    |                                                                   |
     -------------------------------------------------------------------
*/

#ifndef HeapTreeClass_H
#define HeapTreeClass_H

#include <cassert>    // For error-checking purposes

//-------------------------------------------------
// Main structure of HeapTree Class:
//-------------------------------------------------

template <class Elem>
class HeapTree
{
  public:
    HeapTree(int MaxSize=500);
    HeapTree(const HeapTree<Elem> &OtherTree);
    HeapTree(Elem *Array, int ElemNum, int MaxSize);
    Elem *Sort(void); // Built-in HeapSort Algorithm
    ~HeapTree(void);

    bool Add(const Elem &Item);  // Add the Item to Heap
    Elem Remove(void);           // Remove and return Item from Heap

    inline int GetSize(void);    // Returns the number of nodes in the Heap

  protected:
    Elem     *Data;              // Actual Data array
    int       CurrentNum;        // Current number of elements
    const int MAX_SIZE;          // The maximum number of elements

    void ShiftUp(int Node);      // Shift Node up into place
    void ShiftDown(int Node);    // Shift Node down into place

    inline int ParentOf(int Node);      // Returns Parent location
    inline int LeftChildOf(int Node);   // Returns Left Child location
};

#include "heaptree.tem"
#endif

