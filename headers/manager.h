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

class Manager {
    public:
    Manager();
    ~Manager();

    void buildAirports(const string& filename);
    void buildAirlines(const string& filename);
    void buildFlights(const string& filename);

    Airport getAirport(const string &code);

    Airline getAirline(const string &code);

    list<vector<pair<Airport, string>>> getAirportsTraveled(const string &source, const string &target);

    list<vector<pair<Airport, string>>> getAirportsTraveledByCity(const string &source, const string &target);

    list<vector<pair<Airport, string>>> getAirportsTraveledByLocal(double &src_lat, double &src_lon, double &tar_lat, double &tar_lon);

    bool checkAirport(const string &airport);

    bool checkAirline(const string &airline);

    unsigned int getMinFlights(const string& source, const string& target);

    int getNumberOfFlights(const string &code) const;

    int getNumberOfAirlinesFromAirport(const string &airport);

    map<string,double> findAirportsInRadius(double latitude, double longitude, int radius);

    void displayAirportsInTheSameNetwork(const string &code_airport);

    double getShortestPath(const string &source, const string &target);

    list<vector<pair<Airport, string>>> getShortestPathAirports(const string &source, const string &target);

    list<vector<pair<Airport, string>>> getShortestPathCity(const string &source, const string &target);

    list<vector<pair<Airport, string>>> getShortestPathLocal(const double &src_lat, const double &src_lon, const double &tar_lat, const double &tar_lon);

    bool addMarkedAirline(const string &airline);

    bool removeMarkedAirline(const string &airline);

    void clearMarkedAirlines();

    unordered_set<string> getMarkedAirlines();

    deque<Airport> getAirportsReached(const string &airport, const int &num);

    set<string> getCitiesReached(const string &airport, const int &num);

    set<string> getCountriesReached(const string &airport, const int &num);

    private:
    Graph* airports;
    unordered_set<string> cities;
    unordered_map<string, Airline> airlines;
};

#endif
