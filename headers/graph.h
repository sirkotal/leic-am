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
        string dest;   /**< The destination node/airport*/
        string airline;  /**< The airline operating the said route*/
        double distance; /**< The distance between airports/nodes (weight)*/
    };

    struct Node {
        Airport airport; /**<The airport associated to this node*/
        list<Edge> adj; /**< The list of outgoing edges (to adjacent nodes)*/
        bool visited;   /**< A variable that records if the node was visited on a search*/
        list<vector<pair<Airport, string>>> fromSRC; /**<Possible routes from the origin to this point (target)*/
        double distanceSRC; /**< Distance to source airport*/
    };

    unordered_map<string, Node> nodes; /**< Stores the airport code and the node where the said airport is located*/
    int n; /**< Number of nodes/vertices in graph (vertices are numbered from 1 to n)*/
    bool hasDir; /**< A variable that indicates if the graph is directed or undirected*/

    unordered_set<string> marked_airlines; /**<Stores the airlines that we exclusively want to use*/

public:
    /** Graph constructor (default: undirected)
    * @param dir indicates whether the graph is directed or undirected
    */
    Graph(bool dir = false);

    /** Adds edge from source to destination with a certain weight
    * @param source the source node
    * @param target the target node
    * @param airline the airline
    */
    void addEdge(const string &source, const string &target, const string &airline); // Add an edge from an airport to another with their distance as the weight

    /** Adds node to graph
    * @param code the code
    * @param airport the airport
    */
    void addNode(const string &code, const Airport &airport); // Add a node to the graph

    /** Performs a Depth-First Search on the graph
    * @param code_airport the airport's code
    */
    void dfs(const string &code_airport);

    /** Performs a Breadth-First Search on the graph
    * @param code_airport the airport's code
    */
    void bfs(const string &code_airport);

    /** Looks for shortest path between a specific airport and other airports
    * @param code_airport the airport's code
    */
    void shortPath(const string &code_airport);

    /** Marks all nodes in graph as unvisited
    */
    void unvisit();

    /** Finds the shortest path between one source airport and another target airport
     * @param source the source airport's code
     * @param target the target airport's code
     * @return the length of the shortest path between the two airports
     */
    double getShortestPath(const string &source, const string &target);

    /** Calculates the number of flights that depart from an airport
     * @param code the airport's code
     * @return the number of flights that depart from an airport
     */
    int numberOfFlights(const string &code) const;

    /** Returns a list of all the possible routes with minimum number of flights between two airports
     * @param source the source airport's code
     * @param target the target airport's code
     * @return list of all the possible routes with minimum number of flights between the source and target airports
     */
    list<vector<pair<Airport, string>>> getAirportsTraveled(const string &source, const string &target);

    list<vector<pair<Airport, string>>> shortestPathAirports(const string &source, const string &target);

    void addMarkedAirline(const string &airline);

    void removeMarkedAirline(const string &airline);

    void clearMarkedAirlines();

    unordered_set<string> getMarkedAirlines();

    bool checkAirport(const string &airport);

    unsigned int minFlights(const string &source, const string &target);

    Airport getAirport(const string &code) const;

    string findAirport(const double &lat, const double &lon);

    vector<string> findAirportByCity(const string &city);

    int numAirlinesFromAirport(const string &airport);

    map<string,double> findAirportsInRadius(double latitude, double longitude, int radius);

    set<string> getCitiesReached(const string &airport, const int &num);

    deque<Airport> getAirportsReached(const string &airport, const int &num);
    
    set<string> getCountriesReached(const string &airport, const int &num);
    
    unordered_map <string, Graph::Node> getAirportsInTheSameConnectedComponent(const string &code_airport);
};

#endif
