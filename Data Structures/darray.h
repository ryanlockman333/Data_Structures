// Class definition of a darray template

#ifndef _darray
#define _darray

#include <iostream>

// Forward declarations
template <typename T> class darray;
template <typename T> std::ostream& operator << (std::ostream&, const darray<T>&);

template <typename T>
class darray
{
public:
    typedef unsigned size_type;

    // Constructors
    darray();
    darray(const darray<T>&);
    darray(size_type);

    ~darray();

    // Constant members
    size_type size() const;
    size_type capacity() const { return cap; }
    const T& operator [ ] (size_type) const;
    const T* find(const T&) const;

    // Modifiers
    T* find(const T&);
    T& operator [ ] (size_type);
    void pop_back();
    void push_back(const T&);

    friend std::ostream& operator << <T>(std::ostream&, const darray<T>&);
private:
    T* arr;
    size_type used,cap;
};
#include "darray.tem"

#endif
