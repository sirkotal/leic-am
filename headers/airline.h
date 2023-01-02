#ifndef AIRLINE_H
#define AIRLINE_H

#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

class Airline {
    public:
    Airline(string code, string name, string callsign, string country);

    string getCode() const;
    string getName() const;
    string getCallsign() const;
    string getCountry() const;

    bool operator==(const Airline &al2) const;


    private:
        string code;
        string name;
        string callsign;
        string country;
};

#endif
