#include "../headers/menu.h"
#include "../headers/airport.h"
#include "graph.h"
#include "haversine.h"
#include "../headers/airline.h"


void Menu()
{
    int select;
    cout << "FLIGHT ASSISTANCE OPTIONS MENU:" << "\n";
    cout << "\n";
    cout << "[0] " << "Quit" << endl;
    cout << "[1] " << "Display minimum number of flights between Airports" << endl;
    cout << "[2] " << "Display the Number Of Flights" << endl;
    cout << "[3] " << "Display the Shortest Path" << endl;
    cout << "[4] " << "Display Number Of Air lines From Airport" << endl;
    cout << "[5] " << "Display Airports In Radius" << endl;

    cin >> select;

    Manager::buildFlights(const string& filename);
    Manager::buildAirlines(const string& filename);
    Manager::buildAirports(const string& filename);
    Manager::getMinFlights(const string &source, const string &target);
    Manager::getNumberOfFlights(const std::string &code);
    Manager::getShortestPath(const string &source, const string &target);
    Manager::getNumberOfAirlinesFromAirport(const string &airport);
    Manager::findAirportsInRadius(double latitude, double longitude, int radius);


    switch(select)  //dependendo da escolha do utilizador
    {
        case 0:
            cout << "Goodbye!" <<endl;
            break;
        case 1:
            string source, target;
            cout<< "Please type source Airport:" << endl;
            cin >> source;
            cout<< "Please type destination Airport:" << endl;
            cin>> target;
            Manager::getMinFlights(source, target);
            break;

        case 2:
            string code;
            cout << "Please enter Airport code " << endl;
            cin >> code;

            Manager::getNumberOfFlights(code);
            break;

        case 3:
            string source, target;
            cout<< "Please type source Airport:" << endl;
            cin >> source;
            cout<< "Please type destination Airport:" << endl;
            cin>> target;

            Manager::getShortestPath(source, target);
            break;

        case 4:
            string airport;
            cout << "Please enter Airport name " << endl;
            cin >> airport;

            Manager::getNumberOfAirlinesFromAirport(airport);

        case 5:
            double latitude, longitude;
            int radius;

            cout << "Please type the latitude " << endl;
            cin >> latitude;
            cout << "Please type the longitude " << endl;
            cin >> longitude;
            cout << "Please type the radius " << endl;
            cin >> radius;

            Manager::findAirportsInRadius(latitude, longitude, radius);
    }

    cout << "Goodbye!" << endl;
};
