#ifndef FLIGHT_H
#define FLIGHT_H

#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

class Flight {
    public:
    Flight(string source, string target, string airline);

    string getSource() const;
    string getTarget() const;
    string getAirline() const;

    private:
        string source;
        string target;
        string airline;
};

#endif
