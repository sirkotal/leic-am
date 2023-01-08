#include "../headers/menu.h"
#include "../headers/airport.h"
#include "graph.h"
#include "airline.h"
#include "haversine.h"
#include "../headers/airline.h"

Menu::Menu(): manager(Manager()) {}

int main_select = -1;
int select1 = -1;
int select2 = -1;
int select3 = -1;

void Menu::start() {
    do {
        select1 = -1;
        select2 = -1;
        select3 = -1;
        mainMenu();

        switch(main_select) {

            case 1: {
                cout << endl;
                flights();
                break;
            }

            case 2: {
                cout << endl;
                airports();
                break;
            }

            case 3: {
                cout << endl;
                airlines();
                break;
            }
        }

    } while(main_select != 0);
}

void Menu::mainMenu() {
    cout << "_____________________________________________________________________________________" << endl;
    cout << "|                                        MENU                                       |" << endl;
    cout << "|    0. EXIT                                                                        |" << endl;
    cout << "|    1. FLIGHTS                                                                     |" << endl;
    cout << "|    2. AIRPORTS                                                                    |" << endl;
    cout << "|    3. AIRLINES                                                                    |" << endl;
    cout << "|                                                                                   |" << endl;
    cout << " ------------------------------------------------------------------------------------" << endl;
    cout << endl << "Please choose an option: ";
    cin >> main_select;
    cout << endl;
}

void Menu::flightMenu() {
    cout << " ____________________________________________________________________________________" <<  std::endl;
    cout << "|                                    FLIGHTS                                        |" <<  std::endl;
    cout << "|    0. BACK                                                                        |" <<  std::endl;
    cout << "|    1. AIRPORT CODES                                                               |" <<  std::endl;
    cout << "|    2. CITIES                                                                      |" <<  std::endl;
    cout << "|    3. COORDINATES                                                                 |" <<  std::endl;
    cout << "|                                                                                   |" <<  std::endl;
    cout << " ------------------------------------------------------------------------------------" <<  std::endl;
    cout << endl << "Choose how you pretend to search your flight: ";
    cin >> select1;
    cout << endl;
}

void Menu::flights() {
    do {
        flightMenu();

        switch(select1) {

            case 1: {
                string source, target;
                while (true) {
                    cout << "Enter the source airport's code: ";
                    cin >> source;
                    cout << endl;

                    if (manager.checkAirport(source)) {
                        Airport airport = manager.getAirport(source);
                        cout << " ____________________________________________________________________________________" <<  std::endl;
                        cout << "                                       INFO                                          " <<  std::endl;
                        cout << "- Code: " + airport.getAirCode()<<  std::endl;
                        cout << "- Name: " + airport.getName()<<  std::endl;
                        cout << "- City: " + airport.getCity()<<  std::endl;
                        cout << "- Country: " + airport.getCountry()<<  std::endl;
                        cout << "- Latitude: " + to_string(airport.getLatitude())<<  std::endl;
                        cout << "- Longitude: " + to_string(airport.getLongitude())<<  std::endl;
                        cout << " ------------------------------------------------------------------------------------" <<  std::endl;

                        break;
                    }
                    else {
                        cout << "That airport doesn't exist!" << endl;
                    }
                }

                while (true) {
                    cout << "Enter the target airport's code: ";
                    cin >> target;
                    cout << endl;

                    if (manager.checkAirport(target)) {
                        Airport airport = manager.getAirport(target);
                        cout << " ____________________________________________________________________________________" <<  std::endl;
                        cout << "                                       INFO                                          " <<  std::endl;
                        cout << "- Code: " + airport.getAirCode()<<  std::endl;
                        cout << "- Name: " + airport.getName()<<  std::endl;
                        cout << "- City: " + airport.getCity()<<  std::endl;
                        cout << "- Country: " + airport.getCountry()<<  std::endl;
                        cout << "- Latitude: " + to_string(airport.getLatitude())<<  std::endl;
                        cout << "- Longitude: " + to_string(airport.getLongitude())<<  std::endl;
                        cout << " ------------------------------------------------------------------------------------" <<  std::endl;

                        break;
                    }
                    else {
                        cout << "That airport doesn't exist!" << endl;
                    }
                }
                cout << "\n";

                list<vector<pair<Airport, string>>> result = manager.getAirportsTraveled(source, target);

                if (result.empty()) {
                    cout << "There is no available route." << endl;
                    break;
                }

                for (const auto v: result) {
                    int counter = 1;
                    for (const auto a: v) {
                        bool flag = false;
                        if (a.second != "") {
                            flag = true;
                        }
                        cout << a.first.getAirCode();

                        if (flag) {
                            cout << "[" + a.second + "]";
                            flag = false;
                        }
                        if (counter != v.size()) {
                            cout << " -> ";
                        }
                        counter++;
                    }
                    cout << endl;
                }

                break;
            }
            case 2: {
                string source, target;

                cout << "Enter the source city: ";
                cin >> source;
                cout << endl;


                cout << "Enter the target city: ";
                cin >> target;
                cout << endl;


                list<vector<pair<Airport, string>>> result = manager.getAirportsTraveledByCity(source, target);

                if (result.empty()) {
                    cout << "There is no available route." << endl;
                    break;
                }

                for (const auto v: result) {
                    int counter = 1;
                    for (const auto a: v) {
                        bool flag = false;
                        if (a.second != "") {
                            flag = true;
                        }
                        cout << a.first.getAirCode();

                        if (flag) {
                            cout << "[" + a.second + "]";
                            flag = false;
                        }
                        if (counter != v.size()) {
                            cout << " -> ";
                        }
                        counter++;
                    }
                    cout << endl;
                }

                break;
            }
            case 3: {
                double src_lat, src_lon, tar_lat, tar_lon;

                cout << "Enter the source latitude: ";
                cin >> src_lat;
                cout << endl;

                cout << "Enter the source longitude: ";
                cin >> src_lon;
                cout << endl;

                cout << "Enter the target latitude: ";
                cin >> tar_lat;
                cout << endl;


                cout << "Enter the target longitude: ";
                cin >> tar_lon;
                cout << endl;


                list<vector<pair<Airport, string>>> result = manager.getAirportsTraveledByLocal(src_lat, src_lon, tar_lat, tar_lon);

                if (result.empty()) {
                    cout << "There is no available route." << endl;
                    break;
                }

                for (const auto v: result) {
                    int counter = 1;
                    for (const auto a: v) {
                        bool flag = false;
                        if (a.second != "") {
                            flag = true;
                        }
                        cout << a.first.getAirCode();

                        if (flag) {
                            cout << "[" + a.second + "]";
                            flag = false;
                        }
                        if (counter != v.size()) {
                            cout << " -> ";
                        }
                        counter++;
                    }
                    cout << endl;
                }

                break;
            }
        }

    } while(select1 != 0);
}

void Menu::airportMenu() {
    cout << " ____________________________________________________________________________________" <<  std::endl;
    cout << "|                                   AIRPORTS                                        |" <<  std::endl;
    cout << "|    0. BACK                                                                        |" <<  std::endl;
    cout << "|    1. INFO                                                                        |" <<  std::endl;
    cout << "|    2. NUMBER OF FLIGHTS FROM AIRPORT                                              |" <<  std::endl;
    cout << "|    3. NUMBER OF AIRLINES FROM AIRPORT                                             |" <<  std::endl;
    cout << "|    4. AIRPORTS IN A CERTAIN RADIUS                                                |" <<  std::endl;
    cout << "|    5. AIRPORTS IN THE SAME FLIGHT NETWORK                                         |" <<  std::endl;
    cout << "|    6. AIRPORTS REACHABLE IN N FLIGHTS                                             |" <<  std::endl;
    cout << "|    7. CITIES REACHABLE IN N FLIGHTS                                               |" <<  std::endl;
    cout << "|    8. COUNTRIES REACHABLE IN N FLIGHTS                                            |" <<  std::endl;
    cout << "|                                                                                   |" <<  std::endl;
    cout << " ------------------------------------------------------------------------------------" <<  std::endl;
    cout << endl << "Please choose an option: ";
    cin >> select2;
    cout << endl;
}

void Menu::airports() {
    do {
        airportMenu();

        switch (select2) {

            case 1: {
                string code;
                while (true) {
                    cout << "Enter the airport's code: ";
                    cin >> code;
                    cout << endl;

                    if (manager.checkAirport(code)) {
                        Airport airport = manager.getAirport(code);
                        cout << " ____________________________________________________________________________________" << std::endl;
                        cout << "                                       INFO                                          " << std::endl;
                        cout << "- Code: " + airport.getAirCode() << std::endl;
                        cout << "- Name: " + airport.getName() << std::endl;
                        cout << "- City: " + airport.getCity() << std::endl;
                        cout << "- Country: " + airport.getCountry() << std::endl;
                        cout << "- Latitude: " + to_string(airport.getLatitude()) << std::endl;
                        cout << "- Longitude: " + to_string(airport.getLongitude()) << std::endl;
                        cout << " ------------------------------------------------------------------------------------" << std::endl;

                        break;
                    } else {
                        cout << "That airport doesn't exist!" << endl;
                    }
                }
                break;
            }
            case 2: {
                string code;
                while (true) {
                    cout << "Enter the airport's code: ";
                    cin >> code;
                    cout << endl;

                    if (manager.checkAirport(code)) {
                        cout << "Number of flights from this airport: " << manager.getNumberOfFlights(code) << endl;
                        break;
                    }
                    else {
                        cout << "That airport doesn't exist!" << endl;
                    }
                }
                break;
            }

            case 3: {
                string code;
                while (true) {
                    cout << "Enter the airport's code: ";
                    cin >> code;
                    cout << endl;

                    if (manager.checkAirport(code)) {
                        cout << "Number of airlines operating from this airport: " << manager.getNumberOfAirlinesFromAirport(code) << endl;
                        break;
                    }
                    else {
                        cout << "That airport doesn't exist!" << endl;
                    }
                }
                break;
            }
            case 4: {
                double lat, lon;
                int rad;
                cout << "Enter the latitude: ";
                cin >> lat;
                cout << endl;
                cout << "Enter the longitude: ";
                cin >> lon;
                cout << endl;
                cout << "Enter the radius: ";
                cin >> rad;
                cout << endl;

                map<string, double> res = manager.findAirportsInRadius(lat, lon, rad);

                if (res.empty()) {
                    cout << "There are no airports in that area!" << endl;
                    break;
                }

                cout << " ____________________________________________________________________________________" << std::endl;
                cout << "                                      AIRPORTS                                       " << std::endl;
                for (auto itr = res.begin(); itr != res.end(); itr++) {
                    cout << "- Code: " + itr->first << ", " << itr->second << " km" <<  std::endl;
                }
                cout << " ------------------------------------------------------------------------------------" << std::endl;

                break;
            }
            case 5: {
                string code;
                while (true) {
                    cout << "Enter the airport's code: ";
                    cin >> code;
                    cout << endl;

                    if (manager.checkAirport(code)) {
                        manager.displayAirportsInTheSameNetwork(code);
                        break;
                    }
                    else {
                        cout << "That airport doesn't exist!" << endl;
                    }
                }
                break;
            }
            case 6: {
                string code;
                int num;
                while (true) {
                    cout << "Enter the airport's code: ";
                    cin >> code;
                    cout << endl;

                    cout << "Enter the number of flights: ";
                    cin >> num;
                    cout << endl;

                    if (manager.checkAirport(code)) {
                        break;
                    }
                    else {
                        cout << "That airport doesn't exist!" << endl;
                    }
                }
                deque<Airport> res = manager.getAirportsReached(code, num);

                cout << " ____________________________________________________________________________________" << std::endl;
                cout << "                                      AIRPORTS                                       " << std::endl;
                for (auto itr = res.begin(); itr != res.end(); itr++) {
                    cout << "- " + itr->getName() << ", " << itr->getAirCode() << ", " << itr->getCity() << endl;
                }
                cout << " ------------------------------------------------------------------------------------" << std::endl;

                break;
            }
            case 7: {
                string code;
                int num;
                while (true) {
                    cout << "Enter the airport's code: ";
                    cin >> code;
                    cout << endl;

                    cout << "Enter the number of flights: ";
                    cin >> num;
                    cout << endl;

                    if (manager.checkAirport(code)) {
                        break;
                    }
                    else {
                        cout << "That airport doesn't exist!" << endl;
                    }
                }
                set<string> res = manager.getCitiesReached(code, num);

                cout << " ____________________________________________________________________________________" << std::endl;
                cout << "                                       CITIES                                        " << std::endl;
                for (auto itr = res.begin(); itr != res.end(); itr++) {
                    cout << "- " + *itr << endl;
                }
                cout << " ------------------------------------------------------------------------------------" << std::endl;

                break;
            }
            case 8: {
                string code;
                int num;
                while (true) {
                    cout << "Enter the airport's code: ";
                    cin >> code;
                    cout << endl;

                    cout << "Enter the number of flights: ";
                    cin >> num;
                    cout << endl;

                    if (manager.checkAirport(code)) {
                        break;
                    }
                    else {
                        cout << "That airport doesn't exist!" << endl;
                    }
                }
                set<string> res = manager.getCountriesReached(code, num);

                cout << " ____________________________________________________________________________________" << std::endl;
                cout << "                                    COUNTRIES                                        " << std::endl;
                for (auto itr = res.begin(); itr != res.end(); itr++) {
                    cout << "- " + *itr << endl;
                }
                cout << " ------------------------------------------------------------------------------------" << std::endl;

                break;
            }
        }
    } while (select2 != 0);
}

void Menu::airlineMenu() {
    cout << " ____________________________________________________________________________________" <<  std::endl;
    cout << "|                                   AIRLINES                                        |" <<  std::endl;
    cout << "|    0. BACK                                                                        |" <<  std::endl;
    cout << "|    1. INFO                                                                        |" <<  std::endl;
    cout << "|    2. LIST MARKED AIRLINES                                                        |" <<  std::endl;
    cout << "|    3. ADD MARKED AIRLINE                                                          |" <<  std::endl;
    cout << "|    4. REMOVE MARKED AIRLINE                                                       |" <<  std::endl;
    cout << "|    5. CLEAR MARKED AIRLINE                                                        |" <<  std::endl;
    cout << "|                                                                                   |" <<  std::endl;
    cout << " ------------------------------------------------------------------------------------" <<  std::endl;
    cout << endl << "Please choose an option: ";
    cin >> select3;
    cout << endl;
}

void Menu::airlines() {
    do {
        airlineMenu();

        switch(select3) {

            case 1: {
                string code;
                cout << "Enter the airline's code: ";
                cin >> code;

                if (manager.checkAirline(code)) {
                    Airline airline = manager.getAirline(code);
                    cout << " ____________________________________________________________________________________" <<  std::endl;
                    cout << "                                       INFO                                          " <<  std::endl;
                    cout << "- Code: " + airline.getCode() <<  std::endl;
                    cout << "- Name: " + airline.getName() <<  std::endl;
                    cout << "- Callsign: " + airline.getCallsign() <<  std::endl;
                    cout << "- Country: " + airline.getCountry()<<  std::endl;
                    cout << " ------------------------------------------------------------------------------------" <<  std::endl;
                }
                break;
            }
            case 2: {
                unordered_set<string> lst = manager.getMarkedAirlines();
                cout << " ____________________________________________________________________________________" <<  std::endl;
                cout << "                                     AIRLINES                                        " <<  std::endl;
                for (auto itr = lst.begin(); itr != lst.end(); itr++) {
                    cout << "- " + *itr << endl;
                }
                cout << " ------------------------------------------------------------------------------------" <<  std::endl;
                break;
            }
            case 3: {
                string code;
                cout << "Enter the airline's code: ";
                cin >> code;
                bool flag = manager.addMarkedAirline(code);

                if (flag) {
                    cout << "Airline successfully added to the marked airlines' list." << endl;
                }
                else {
                    cout << "Operation was unsuccessful." << endl;
                }
                break;
            }
            case 4: {
                string code;
                cout << "Enter the airline's code: ";
                cin >> code;
                bool flag = manager.removeMarkedAirline(code);

                if (flag) {
                    cout << "Airline successfully removed from the marked airlines' list." << endl;
                }
                else {
                    cout << "Operation was unsuccessful." << endl;
                }
                break;
            }
            case 5: {
                manager.clearMarkedAirlines();
                break;
            }
        }

    } while(select3 != 0);
}
