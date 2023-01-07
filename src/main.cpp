#include <bits/stdc++.h>
#include "../headers/airport.h"
#include "../headers/manager.h"

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
    cout << man.getShortestPathCity("New York", "Lisbon") << endl;
    cout << man.getShortestPathLocal(40.63691, -8.04331, 42.70467, -7.73570) << endl;
    for (auto v: man.test("OPO", "VGO")) {
        for (auto p: v) {
            cout << p.first.getAirCode() << endl;
        }
    }
}