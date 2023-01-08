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
    Menu();

    void start();

    void mainMenu();

    void flightMenu();

    void airportMenu();

    void airlineMenu();
private:
    Manager manager;
};

#endif
