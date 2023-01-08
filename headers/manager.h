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

    list<vector<pair<Airport, string>>> getAirportsTraveled(const string &source, const string &target);

    bool addMarkedAirline(const string &airline);

    bool checkAirport(const string &airport);

    bool checkAirline(const string &airline);

    unsigned int getMinFlights(const string& source, const string& target);
    int getNumberOfFlights(const string &code) const;

    double getShortestPath(const string &source, const string &target);

    int getNumberOfAirlinesFromAirport(const string &airport);

    map<double,string> findAirportsInRadius(double latitude, double longitude, int radius);

    double getShortestPathCity(const string &source, const string &target);

    double getShortestPathLocal(const double &src_lat, const double &src_lon, const double &tar_lat, const double &tar_lon);

    private:
    Graph* airports;
    unordered_set<string> cities;
    unordered_map<string, Airline> airlines;
};

#endif
