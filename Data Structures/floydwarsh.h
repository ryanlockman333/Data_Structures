/*
 * Ryan Lockman
 * floydwarsh.h
 * Description: floydwarsh class prototypes
 *
*/

/*
// Pre/Post Conditions
FloydWarsh(const unsigned size = sizeof(Graph));
    Post: Initializes the Graph by default.
void calcFloydWarsh();
    Post: Calculates the Matrix for shortest path view.
Graph& getGraph();
    Post: Returns a reference to the Graph for use.
void printFloydMatrix() const;
    Post: Prints the matrix out. Call once before for original and then again after calcFloydWarsh().
*/

#ifndef FLOYDWARSH_H
#define FLOYDWARSH_H

// Headers
#include <vector>

template<typename T> class FloydWarsh {
public:
    // Typedefs
    typedef T value_type;
    typedef std::vector<std::vector<T> > Graph;
    typedef std::vector<T> Vector;

    // Constructors
    FloydWarsh(const unsigned size = sizeof(Graph)); // default

    // Modification Members
    void calcFloydWarsh();
    Graph& getGraph() { return G; }

    // Other Members
    void printFloydMatrix() const;

private:
    // Data Members
    Graph G;
};

#include "floydwarsh.tem"
#endif

