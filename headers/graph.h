#ifndef _GRAPH_H_
#define _GRAPH_H_

#include "airport.h"

#include <list>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <iostream>

using namespace std;

class Graph {
    struct Edge {
        string dest;   // Destination node/airport
        string airline;  // Airline operating the said route
        double distance; // distance between airports/nodes (weight)
    };

    struct Node {
        Airport airport;
        list<Edge> adj; // The list of outgoing edges (to adjacent nodes)
        bool visited;   // Has the node been visited on a search?
        vector<Airport> fromSRC; // Airports that were visited from the origin to this point (target)
        /*double distanceSRC; // Distance to source airport (shortest path?)*/
    };

    unordered_map<string, Node> nodes; // hash table - { airport_code, node }
    int n;              // Graph size (vertices are numbered from 1 to n)
    bool hasDir;        // false: undirected; true: directed

public:
    // Constructor: nr nodes and direction (default: undirected)
    Graph(bool dir = false);

    void addEdge(const string& source, const string& target, const string& airline); // Add an edge from an airport to another with their distance as the weight

    void addNode(const string &code, const Airport &airport); // Add a node to the graph

    void unvisit(); // Set all nodes to unvisited

    void dfs(const string &code_airport);

    void bfs(const string &code_airport);

    void shortestPath(const string &airport_code);

    Airport getAirport(const string &code) const;

    int numberOfFlights(const string &code) const;

    unsigned int minFlights(const string& source, const string& target);
};

#endif
