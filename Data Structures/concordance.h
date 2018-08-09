/********************************************************************************************* 
 * Ryan Lockman                                                                              *
 * Concordance.h                                                                             *
 * Description: Concordance class prototypes.                                                *
 * 4/16/14                                                                                   *
 *********************************************************************************************/

// Macro
#ifndef CONCORDANCE_H
#define CONCORDANCE_H

// Headers
#include <string>
#include <map>
#include "forward_list.h"

// Concordance Class
class Concordance {
public:
// Typedefs
    typedef std::string key_type;
    typedef Forward_List<std::size_t> FList;
    typedef std::map<key_type, FList> Map;

    typedef Map::value_type value_type;
    typedef Map::size_type size_type;
    typedef Map::difference_type difference_type;

    typedef Map::iterator iterator;
    typedef Map::reference reference;
    typedef Map::pointer pointer;
    typedef Map::const_iterator const_iterator;
    typedef Map::const_reference const_reference;
    typedef Map::const_pointer const_pointer;

// Constructors
    explicit Concordance(const Map &data = Map()) : myMap(data) {}
    // Post: Initializes data members.

// Modification Functions
    int fin_concord(const char* const path);
    // Pre:  Specified file path must be correct path.
    // Post: Fill Map with word concordance. Returns -1 on fail, 0 on success.
    void erase_index(key_type key) { myMap.erase(key); }
    // Post: Erases specified key_type(word).

// Constant Functions
    int fout_concord(const char* const path) const;
    // Pre:  Specified file path must be correct path.
    // Post: Outputs Map to a specified file. Returns -1 on fail, 0 on success.
    template<typename OutStream> void print(OutStream &os) const;
    // Post: Prints Map concordance to stdout or output file.
    size_type size() const { return myMap.size(); }
    // Post: Returns the sie of the Map;
    bool empty() const { return myMap.empty(); }
    // Post: Returns ture if Map is empty, false otherwise.

// Iterator Functions
    iterator begin() { return iterator(myMap.begin()); }
    // Post: Returns a non const iterator to the first element of the list.
	iterator end()   { return iterator(myMap.end()); }
    // Post: Returns a non const iterator to one past the last element of the list.
	const_iterator begin() const { return const_iterator(myMap.begin()); }
    // Post: Returns a const iterator to the first element of the list.
	const_iterator end()   const { return const_iterator(myMap.end()); }
    // Post: Returns a const iterator to one past the last element of the list.

private:
// Data Members
    Map myMap;
};

#include "concordance.tem"
#endif

