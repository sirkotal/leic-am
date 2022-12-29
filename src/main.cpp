#include <bits/stdc++.h>
#include "../headers/airport.h"
#include "../headers/manager.h"

#define airports "../air_data/airports.csv"

using namespace std;

int main() {
    Manager man;
    Airport porto("OPO", "Francisco Sá Carneiro", "Porto", "Portugal", 41.0, 11.0);
    cout << "Hello World!" << endl;
    cout << porto.getCountry() << endl;
    man.buildAirports(airports);
}