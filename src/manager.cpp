#include "../headers/manager.h"

void Manager::buildAirports(const string& filename) {
    string air_code, name, city, country, lat, lon;

    ifstream thefile(filename);

    int id = 1;

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

            Airport temp(air_code, name, city, country, d_lat, d_lon);
            airports.emplace(id, temp);

            id++;
        }
        //cout << id << endl;
        thefile.close();
    }
    else
    {
        cout << "Error: The program was unable to open the file.";
    }
}