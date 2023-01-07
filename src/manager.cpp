#include "../headers/manager.h"

#define airportsF "../air_data/airports.csv"
#define flightsF "../air_data/flights.csv"
#define airlinesF "../air_data/airlines.csv"

Manager::Manager() {
    this->airports = new Graph(true);
    buildAirports(airportsF);
    buildFlights(flightsF);
    buildAirlines(airlinesF);
}

Manager::~Manager() {
    delete airports;
}

void Manager::buildAirports(const string& filename) {
    string air_code, name, city, country, lat, lon;

    ifstream thefile(filename);

    if (thefile.is_open())
    {
        string line;
        getline(thefile, line);

        while (!thefile.eof()) {
            getline(thefile, air_code, ',');
            getline(thefile, name, ',');
            getline(thefile, city, ',');
            getline(thefile, country, ',');
            getline(thefile, lat, ',');
            getline(thefile, lon, '\n');

            double d_lat = stod(lat);
            double d_lon = stod(lon);

            airports->addNode(air_code, Airport(air_code, name, city, country, d_lat, d_lon));
            cities.insert(city);
        }
        thefile.close();
    }
    else
    {
        cout << "Error: The program was unable to open the file.";
    }
}

void Manager::buildAirlines(const string& filename) {
    string code, name, callsign, country;

    ifstream thefile(filename);

    if (thefile.is_open())
    {
        string line;
        getline(thefile, line);

        while (!thefile.eof()) {
            getline(thefile, code, ',');
            getline(thefile, name, ',');
            getline(thefile, callsign, ',');
            getline(thefile, country, '\n');

            airlines.insert({code, Airline(code, name, callsign, country)});
        }
        //cout << airlines.begin()->getName() << endl;
        thefile.close();
    }
    else
    {
        cout << "Error: The program was unable to open the file.";
    }
}

void Manager::buildFlights(const string& filename) {
    string source, target, airline;

    ifstream thefile(filename);

    if (thefile.is_open())
    {
        string line;
        getline(thefile, line);

        while (!thefile.eof()) {
            getline(thefile, source, ',');
            getline(thefile, target, ',');
            getline(thefile, airline, '\n');

            airports->addEdge(source, target, airline);
        }
        thefile.close();
    }
    else
    {
        cout << "Error: The program was unable to open the file.";
    }
}

unsigned int Manager::getMinFlights(const string &source, const string &target) {
    return airports->minFlights(source, target);
}

int Manager::getNumberOfFlights(const std::string &code) const {
    return airports->numberOfFlights(code);
}

double Manager::getShortestPath(const string &source, const string &target) {
    return airports->getShortestPath(source, target);
}

int Manager::getNumberOfAirlinesFromAirport(const string &airport) {
    return airports->numAirlinesFromAirport(airport);
}

map<double,string> Manager::findAirportsInRadius(double latitude, double longitude, int radius) {
    return airports->findAirportsInRadius(latitude, longitude, radius);
}

void Manager::displayAirtportsInTheSameNetwork(const string &code_airport){
    for (auto &element : airports->getAirtportsInTheSameConnectedComponent(code_airport))
    {
        cout << element.second.airport.getName() << ";" << element.second.airport.getCity() << ";" << element.second.airport.getCountry() << endl;
    }
}