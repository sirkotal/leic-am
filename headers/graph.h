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
     * @returns the length of the shortest path between the two airports
     */
    double getShortestPath(const string &source, const string &target);

    /** Calculates the number of flights that depart from an airport
     * @param code the airport's code
     * @returns the number of flights that depart from an airport
     */
    int numberOfFlights(const string &code) const;

    /** Returns a list of all the possible routes with minimum number of flights between two airports
     * @param source the source airport's code
     * @param target the target airport's code
     * @returns list of all the possible routes with minimum number of flights between the source and target airports
     */
    list<vector<pair<Airport, string>>> getAirportsTraveled(const string &source, const string &target);

    /** Gives a list of airports that belong to shortest path between a source airport and a target airport
    * @param source the source airport's code
    * @param target the target airport's code
    * @returns the list of airports that belong to shortest path between the source airport and the target airport
    */
    list<vector<pair<Airport, string>>> shortestPathAirports(const string &source, const string &target);

    /** Adds a marked airline to the airlines set
    * @param airline the airline's code
    */
    void addMarkedAirline(const string &airline);

    /** Removes a marked airline from the airlines set
    * @param airline the airline's code
    */
    void removeMarkedAirline(const string &airline);

    /** Clears the marked airlines set
    */
    void clearMarkedAirlines();

    /** Gets the marked airlines set
    * @returns the marked airlines set
    */
    unordered_set<string> getMarkedAirlines();

    /** Calculates the minimum number of flights between two airports
    * @param airport the airport's code
    * @returns the minimum number of flights between two airports
    */
    bool checkAirport(const string &airport);

    /** Calculates the minimum number of flights between two airports
    * @param source the source airport's code
    * @param target the target airport's code
    * @returns the minimum number of flights between two airports
    */
    unsigned int minFlights(const string &source, const string &target);

    /** Gets the airport with a certain code
    * @param code airport's code
    * @returns the airport with a certain code
    */
    Airport getAirport(const string &code) const;

    /** Finds the nearest airport to a point on Earth
    * @param lat point's latitude
    * @param lon point's longitude
    * @returns the nearest airport to that point on Earth
    */
    string findAirport(const double &lat, const double &lon);

    /** Finds the airports near a city
    * @param city the city's name
    * @returns a vector of airports near that city
    */
    vector<string> findAirportByCity(const string &city);

    /** Calculates the number of airlines that operate from an airport
    * @param airport the airport
    * @returns the number of airlines that operate from an airport
    */
    int numAirlinesFromAirport(const string &airport);

    /** Finds the airports in a certain radius of a specific point on Earth
    * @param latitude the point's latitude
    * @param longitude the point's longitude
    * @param radius the radius in which we want to find the airports
    * @returns the map of airports in a certain radius of a specific point on Earth
    */
    map<string,double> findAirportsInRadius(double latitude, double longitude, int radius);

    /** Gets the set of cities reached from a source airport in num flights
    * @param airport the source airport
    * @param num the number of flights
    * @returns the set of cities reached from a source airport in num flights
    */
    set<string> getCitiesReached(const string &airport, const int &num);

    /** Gets the deque of airports reached from a source airport in num flights
    * @param airport the source airport
    * @param num the number of flights
    * @returns the deque of airports reached from a source airport in num flights
    */
    deque<Airport> getAirportsReached(const string &airport, const int &num);

    /** Gets the set of countries reached from a source airport in num flights
    * @param airport the source airport
    * @param num the number of flights
    * @returns the set of cities reached from a source airport in num flights
    */
    set<string> getCountriesReached(const string &airport, const int &num);

    /** Gets the airports in the same connected component as a source airport
    * @param airport the source airport
    * @param num the number of flights
    * @returns the set of cities reached from a source airport in num flights
    */
    unordered_map <string, Graph::Node> getAirportsInTheSameConnectedComponent(const string &code_airport);
};

#endif
