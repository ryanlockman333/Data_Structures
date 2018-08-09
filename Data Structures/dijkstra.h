/*
 * Ryan Lockman
 * dijkstra.h
 * Description: dijkstra class prototypes
*/

/*
// Pre/Post Conditions
Dijkstra(const unsigned size = 2*sizeof(Graph));
    Post: Initializes the data structure by default.
void calcDijkstra(const int source, const int dest);
    Post: Calculates the shortest path and stores it in path variable.
Graph& getGraph();
    Post: Returns a reference to the Graph for use.
U getTotalWeight() const;
    Post: Returns the totalWeight of the shortest path.
void printPath() const;
    Post: Prints out the shortest path.
*/

#ifndef DIJKSTRA_H
#define DIJKSTRA_H

// Headers
#include <vector>
#include <utility>
#include "pqueue.h"

template<typename T, typename U> class Dijkstra {
public:
    // Typedefs
    typedef T value_type;
    typedef std::pair<T, U> Pair;
    typedef PriorQueue<Pair> PQueue;
    typedef std::vector<std::vector<Pair> > Graph;
    
    // Constructors
    Dijkstra(const unsigned size = 2*sizeof(Graph)) : PQ(), G(size), path(), totalWeight() {} // default

    // Modification Members
    void calcDijkstra(const int source, const int dest);
    Graph& getGraph() { return G; }

    // Constant Mmebers
    U getTotalWeight() const { return totalWeight; }

    // Other Members
    void printPath() const;

private:
    //Data Members
    PQueue PQ;
    Graph G;
    std::vector<T> path;
    U totalWeight;
};

#include "dijkstra.tem"
#endif

