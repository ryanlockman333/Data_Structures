/*
 **************************************************
 * Ryan Lockman                                   *
 * 101430670                                      *
 * bucket.h                                       *
 * Description: Bucket Prototypes/Implementations *
 **************************************************
*/

// Macro
#ifndef BUCKET_H
#define BUCKET_H

// Headers
#include <cstdlib>

// Class
template<class T> class Bucket {
public:
    // Constructors
    explicit Bucket(int keyIn = -1, T dataIn = T()) : key(keyIn), data(dataIn) {} // default
    
    // Modification Member Functions
    void setKey(const int keyIn)  { key = keyIn; }
    void setData(const T &dataIn) { data = dataIn; }

    // Get Member Functions
    int getKey()  { return key; }
    T&  getData() { return data; }

    // Constant Member Functions
    const int getKey()  const { return key; }
    const T&  getData() const { return data; }
private:
    // Data Members
    int key;
    T data;
};

#endif

