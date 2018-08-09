/********************************************************************************************* 
 * Ryan Lockman                                                                              *
 * freq_occur.h                                                                              *
 * Description: Frequencey of Occurence class prototypes.                                    *
 * 4/16/14                                                                                   *
 *********************************************************************************************/

// Macro
#ifndef FREQ_OCCUR_H
#define FREQ_OCCUR_H

// Headers
#include <string>
#include <map>

// Freq_Occur Class
class Freq_Occur {
public:
// Typedefs
    typedef char key_type;
    typedef unsigned mapped_type;
    typedef std::map<key_type, mapped_type> Map;

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
    explicit Freq_Occur(const Map &data = Map()) : myMap(data) {}
    // Post: Initializes Data Members

// Modification Functions
    int fin_occur(const char* const path, std::string ignoredChrs);
    // Pre:  Specified file path must be correct path and ignored must be string of letters.
    // Post: Fills our Map with letter occurences. Returns -1 on fail, 0 on success.
    void erase_occur(key_type key) { myMap.erase(key); }
    // Post: Erases a given key_type(letter).

// Constant Functions
    int fout_occur(const char* const path) const;
    // Pre:  Specified file path must be correct path.
    // Post: Prints Map's contents to a specified file path. Returns -1 on fail, 0 on success.
    template<typename OutStream> void print(OutStream &os) const;
    // Post: Prints our Map to stdout or output file.
    bool empty() const { return myMap.empty(); }
    // Post: Returns true if Map is empty, false otherwise.
    size_type size() const { return myMap.size(); }
    // Post: Returns size of the Map.

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

// Helper Functions
    unsigned lenHelper(const unsigned x) const;
};

#include "freq_occur.tem"
#endif

