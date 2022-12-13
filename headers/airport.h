#ifndef AIRPORT_H
#define AIRPORT_H

#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

class Airport {
    public:
    Airport(string air_code, string name, string city, string country, double lat, double lon);

    string getAirCode() const;
    string getName() const;
    string getCity() const;
    string getCountry() const;
    double getLatitude() const;
    double getLongitude() const;


    private:
        string air_code;
        string name;
        string city;
        string country;
        double lat;
        double lon;
};

#endif
