#ifndef _GRAPH_H_
#define _GRAPH_H_
class Graph;

#include "airport.h"

#include <iostream>
#include <limits>
#include <list>
#include <vector>
#include <set>
#include <queue>
#include <deque>
#include <map>
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
        list<vector<pair<Airport, string>>> fromSRC; // Airports that were visited from the origin to this point (target)
        double distanceSRC; // Distance to source airport (shortest path?)
    };

    unordered_map<string, Node> nodes; // hash table - { airport_code, node }
    int n;              // Graph size (vertices are numbered from 1 to n)
    bool hasDir;        // false: undirected; true: directed

    unordered_set<string> marked_airlines; // airlines we want to use

public:
    // Constructor: nr nodes and direction (default: undirected)
    Graph(bool dir = false);

    void addEdge(const string &source, const string &target, const string &airline); // Add an edge from an airport to another with their distance as the weight

    void addNode(const string &code, const Airport &airport); // Add a node to the graph

    list<vector<pair<Airport, string>>> getAirportsTraveled(const string &source, const string &target);

    list<vector<pair<Airport, string>>> shortestPathAirports(const string &source, const string &target);

    void addMarkedAirline(const string &airline);

    void removeMarkedAirline(const string &airline);

    void clearMarkedAirlines();

    unordered_set<string> getMarkedAirlines();

    void unvisit(); // Set all nodes to unvisited

    bool checkAirport(const string &airport);

    void dfs(const string &code_airport);

    void bfs(const string &code_airport);

    void shortPath(const string &code_airport);

    double getShortestPath(const string &source, const string &target);

    int numberOfFlights(const string &code) const;

    unsigned int minFlights(const string &source, const string &target);

    Airport getAirport(const string &code) const;

    string findAirport(const double &lat, const double &lon);

    vector<string> findAirportByCity(const string &city);

    int numAirlinesFromAirport(const string &airport);

    map<string,double> findAirportsInRadius(double latitude, double longitude, int radius);

    set<string> getCitiesReached(const string &airport, const int &num);

    deque<Airport> getAirportsReached(const string &airport, const int &num);
    
    set<string> getCountriesReached(const string &airport, const int &num);

    set<string> getAirportsAtArrival(const string &airport);

    set<string> getCitiesAtArrival(const string &airport);
    
    unordered_map <string, Graph::Node> getAirportsInTheSameConnectedComponent(const string &code_airport);
};

#endif
