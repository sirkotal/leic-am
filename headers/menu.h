#ifndef LEIC_AM_MENU_H
#define LEIC_AM_MENU_H

#include <bits/stdc++.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "manager.h"

using namespace std;

class Menu {
public:
    Menu();

    void start();

    void mainMenu();

    void flights();

    void flightMenu();

    void flightNumMenu();

    void flightsNum();

    void flightDistMenu();

    void flightsDist();

    void airportMenu();

    void airports();

    void airlineMenu();

    void airlines();

private:
    Manager manager;
};

#endif
