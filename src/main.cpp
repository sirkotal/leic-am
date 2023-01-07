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
    cout << "Hello World!" << endl;
    cout << porto.getCountry() << endl;
    cout << man.getMinFlights("CDG", "LGA") << endl;
    cout << man.getNumberOfFlights("OPO") << endl;
    cout << man.getShortestPath("CDG", "LGA") << endl;
    cout << man.getNumberOfAirlinesFromAirport("LIS") << endl;
    cout << man.findAirportsInRadius(39.4140, -8.0750, 200).size() << endl;
    man.displayAirportsInTheSameNetwork("ORY");
}