#include "../headers/manager.h"

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

            airlines.emplace_back(code, name, callsign, country);
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

            flights.emplace_back(source, target, airline);
        }
        cout << flights.begin()->getSource() << endl;
        thefile.close();
    }
    else
    {
        cout << "Error: The program was unable to open the file.";
    }
}    