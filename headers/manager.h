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
    void buildAirports(const string& filename);
    int sized();

    private:
    unordered_map<int, Airport> airports;
};

#endif
