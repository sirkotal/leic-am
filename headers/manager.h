#ifndef MANAGER_H
#define MANAGER_H

#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "airport.h"
#include "airline.h"
#include "graph.h"

using namespace std;

/**
 * A class to help manage flights
 */
class Manager {
public:
    /** Manager Default Constructor
    */
    Manager();

    /** Manager Default Destructor
    */
    ~Manager();

    /** Initializes airport parameters with data from csv files
    * @param filename the filename
    */
    void buildAirports(const string& filename);

    /** Initializes airline parameters with data from csv files
    * @param filename the filename
    */
    void buildAirlines(const string& filename);

    /** Initializes flight parameters with data from csv files
    * @param filename the filename
    */
    void buildFlights(const string& filename);

    /** Gets the Airport
    *
    * @returns the Airport
    */
    Airport getAirport(const string &code);

    /** Gets the Airline
    *
    * @returns the Airline
    */
    Airline getAirline(const string &code);

    /** Gets the airports traveled from the path with minimum flights between a source airport and a target airport
    * @param source the source airport's code
    * @param target the target airport's code
    * @returns the list of airports traveled
    */
    list<vector<pair<Airport, string>>> getAirportsTraveled(const string &source, const string &target);

    /** Gets the airports traveled from the path with minimum flights between a source city and a target city
    * @param source the source city's name
    * @param target the target airport
    * @returns the list of airports traveled
    */
    list<vector<pair<Airport, string>>> getAirportsTraveledByCity(const string &source, const string &target);

    /** Gets the airports traveled from the path with minimum flights between a source local and a target local
    * @param src_lat the source place's latitude
    * @param src_lon the source place's longitude
    * @param tar_lat the source place's latitude
    * @param tar_lon the target place's longitude
    * @returns the list of airports traveled
    */
    list<vector<pair<Airport, string>>> getAirportsTraveledByLocal(double &src_lat, double &src_lon, double &tar_lat, double &tar_lon);

    /** Checks if the airport exists in the graph
    * @param airport the airport's code
    * @returns boolean value that indicates if the airport exists in the graph
    */
    bool checkAirport(const string &airport);

    /** Checks if the airline exists in the graph
    * @param airport the airport's code
    * @returns boolean value that indicates if the airline exists in the graph
    */
    bool checkAirline(const string &airline);

    /** Calculates the minimum number of flights between two airports
    * @param source the source airport
    * @param target the target airport
    * @returns the minimum number of flights between two airports
    */
    unsigned int getMinFlights(const string& source, const string& target);

    /** Calculates the number of flights that depart from an airport
    * @param code the airport's code
    * @returns the number of flights that depart from the airport
    */
    int getNumberOfFlights(const string &code) const;

    /** Calculates the number of airlines that operate from an airport
    * @param airport the airport
    * @returns the number of airlines that operate from an airport
    */
    int getNumberOfAirlinesFromAirport(const string &airport);

    /** Finds the airports in a certain radius of a specific point on Earth
    * @param latitude the point's latitude
    * @param longitude the point's longitude
    * @param radius the radius in which we want to find the airports
    * @returns the map of airports in a certain radius of a specific point on Earth
    */
    map<string,double> findAirportsInRadius(double latitude, double longitude, int radius);

    /** Displays the airports in the same network of a certain airport
    * @param code_airport the airport's code
    */
    void displayAirportsInTheSameNetwork(const string &code_airport);

    /** Gives the distance between the source airport and the target airport
    * @param source the source airport's code
    * @param target the target airport's code
    * @returns the double value that corresponds to the distance between the source airport and the target airport
    */
    double getShortestPath(const string &source, const string &target);

    /** Gets the list of airports that belong to shortest path between a source airport and a target airport
    * @param source the source airport's code
    * @param target the target airport's code
    * @returns the list of airports that belong to shortest path between the source airport and the target airport
    */
    list<vector<pair<Airport, string>>> getShortestPathAirports(const string &source, const string &target);

    /** Gets the list of cities that belong to shortest path between a source city and a target city
    * @param source the source city's name
    * @param target the target city's name
    * @returns the list of cities that belong to shortest path between the source city and the target city
    */
    list<vector<pair<Airport, string>>> getShortestPathCity(const string &source, const string &target);

    /** Gets the list of places that belong to shortest path between a source place and a target place
    * @param source the source place's latitude
    * @param source the source place's longitude
    * @param target the target place's latitude
    * @param target the target place's longitude
    * @returns the list of cities that belong to shortest path between the source place and the target place
    */
    list<vector<pair<Airport, string>>> getShortestPathLocal(const double &src_lat, const double &src_lon, const double &tar_lat, const double &tar_lon);

    /** Adds a marked airline to the airlines set
    * @param airline the airline's code
    * @returns boolean value that indicates if the operation was succesful
    */
    bool addMarkedAirline(const string &airline);

    /** Removes a marked airline from the airlines set
    * @param airline the airline's code
    * @returns boolean value that indicates if the operation was succesful
    */
    bool removeMarkedAirline(const string &airline);

    /** Clears the marked airlines set
    * @param airline the airline's code
    */
    void clearMarkedAirlines();

    /** Clears the marked airlines set
    * @returns unordered_set of strings of marked airlines' names
    */
    unordered_set<string> getMarkedAirlines();

    deque<Airport> getAirportsReached(const string &airport, const int &num);

    /** Gets the set of cities reached from a source airport in num flights
    * @param airport the source airport
    * @param num the number of flights
    * @returns the set of cities reached from a source airport in num flights
    */
    set<string> getCitiesReached(const string &airport, const int &num);

    /** Gets the set of countries reached from a source airport in num flights
    * @param airport the source airport
    * @param num the number of flights
    * @returns the set of countries reached from a source airport in num flights
    */
    set<string> getCountriesReached(const string &airport, const int &num);

private:
    Graph* airports; /**< The airport's graph*/
    unordered_set<string> cities; /**< The set of cities*/
    unordered_map<string, Airline> airlines; /**< The airlines' hashtable*/
};

#endif
