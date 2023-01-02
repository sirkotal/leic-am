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
#include "flight.h"
#include "graph.h"

using namespace std;

class Manager {
    public:
    Manager();
    ~Manager();
    void buildAirports(const string& filename);
    void buildAirlines(const string& filename);
    void buildFlights(const string& filename);

    int getMinFlights(const string& source, const string& target);

    private:
    Graph* airports;
    unordered_set<string> cities;
    unordered_map<string, Airline> airlines;
};

#endif
