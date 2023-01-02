#include <bits/stdc++.h>
#include "../headers/airport.h"
#include "../headers/manager.h"

#define airports "../air_data/airports.csv"
#define flights "../air_data/flights.csv"
#define airlines "../air_data/airlines.csv"

using namespace std;

int main() {
    Manager man;
    Airport porto("OPO", "Francisco Sá Carneiro", "Porto", "Portugal", 41.0, 11.0);
    man.buildAirports(airports);
    cout << "Hello World!" << endl;
    cout << porto.getCountry() << endl;
    man.buildFlights(flights);
    man.buildAirlines(airlines);
}