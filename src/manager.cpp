#include "../headers/manager.h"

#define airportsF "../air_data/airports.csv"
#define flightsF "../air_data/flights.csv"
#define airlinesF "../air_data/airlines.csv"

#define MAX std::numeric_limits<double>::max()

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

list<vector<pair<Airport, string>>> Manager::getAirportsTraveled(const string &source, const string &target) {
    return airports->getAirportsTraveled(source, target);
}

list<vector<pair<Airport, string>>> Manager::getAirportsTraveledByCity(const string &source, const string &target) {
    bool flag = true;
    vector<string> src_cities = airports->findAirportByCity(source);
    vector<string> tar_cities = airports->findAirportByCity(target);
    list<vector<pair<Airport, string>>> result;
    list<vector<pair<Airport, string>>> tmp;

    for (string src: src_cities) {
        for (string tar: tar_cities) {
            tmp = airports->getAirportsTraveled(src, tar);
            if (flag || result.front().size() > tmp.front().size()) {
                flag=false;
                result = tmp;
            }
            else if (result.front().size() == tmp.front().size()) {
                result.insert(result.end(), tmp.begin(), tmp.end());
            }
        }
    }

    return result;
}

list<vector<pair<Airport, string>>> Manager::getAirportsTraveledByLocal(double &src_lat, double &src_lon, double &tar_lat, double &tar_lon) {
    bool flag = true;
    int radius = 100;
    map<string,double> src_airports = airports->findAirportsInRadius(src_lat, src_lon, radius);
    map<string,double> tar_airports = airports->findAirportsInRadius(tar_lat, tar_lon, radius);
    list<vector<pair<Airport, string>>> result;
    list<vector<pair<Airport, string>>> tmp;

    for (auto src: src_airports) {
        for (auto tar: tar_airports) {
            tmp = airports->getAirportsTraveled(src.first, tar.first);
            if (flag || result.front().size() >= tmp.front().size()) {
                flag=false;
                result = tmp;
            }
        }
    }
    return result;
}

bool Manager::addMarkedAirline(const string &airline) {
    if (airports->getMarkedAirlines().find(airline) != airports->getMarkedAirlines().end()) {
        return false;
    }

    if (airlines.find(airline) == airlines.end()) {
        return false;
    }

    airports->addMarkedAirline(airline);
    return true;
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

double Manager::getShortestPathCity(const string &source, const string &target) {
    vector<string> src_airports = airports->findAirportByCity(source);
    vector<string> tar_airports = airports->findAirportByCity(target);

    double shrt = MAX;

    for (const string &s: src_airports) {
        for (const string &t: tar_airports) {
            double dist = getShortestPath(s, t);

            if (dist < shrt) {
                shrt = dist;
            }
        }
    }
    return shrt;
}

double Manager::getShortestPathLocal(const double &src_lat, const double &src_lon, const double &tar_lat, const double &tar_lon) {
    int rad = 100;
    map<string,double> src_airports = airports->findAirportsInRadius(src_lat, src_lon, rad);
    map<string,double> tar_airports = airports->findAirportsInRadius(tar_lat, tar_lon, rad);

    if (src_airports.empty() || tar_airports.empty()) {
        cout << "No viable route available between these 2 locations!" << endl;
        return -1;
    }

    double shrt = MAX;
    string a1;
    string a2;

    for (auto src = src_airports.begin(); src != src_airports.end(); src++) {
        for (auto tar = tar_airports.begin(); tar != tar_airports.end(); tar++) {
            double dist = getShortestPath(src->first, tar->first);

            if (dist < shrt) {
                shrt = dist;
                a1 = src->first;
                a2 = tar->first;
            }
        }
    }

    cout << a1 << " -> " << a2 << endl;
    return shrt;
}

int Manager::getNumberOfAirlinesFromAirport(const string &airport) {
    return airports->numAirlinesFromAirport(airport);
}

map<string,double> Manager::findAirportsInRadius(double latitude, double longitude, int radius) {
    return airports->findAirportsInRadius(latitude, longitude, radius);
}

void Manager::displayAirportsInTheSameNetwork(const string &code_airport) {
    for (auto &element: airports->getAirtportsInTheSameConnectedComponent(code_airport)) {
        cout << element.second.airport.getName() << ";" << element.second.airport.getCity() << ";"
             << element.second.airport.getCountry() << endl;
    }
}

bool Manager::checkAirport(const string &airport) {
    return airports->checkAirport(airport);
}

bool Manager::checkAirline(const string &airline) {
    return (airlines.find(airline) != airlines.end());
}

Airport Manager::getAirport(const string &code) {
    return airports->getAirport(code);
}