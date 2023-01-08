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
    /** Menu default constructor
     */
    Menu();

    /** Handles user input in the main menu
     */
    void start();

    /** Displays the main menu
     */
    void mainMenu();

    /** Handles user input in the flights menu
     */
    void flights();

    /** Displays the flights options menu
     */
    void flightMenu();

    /** Displays the flights menu for minimum number of airports
     */
    void flightNumMenu();

    /** Handles user input in the flights menu for minimum number of airports
     */
    void flightsNum();

    /** Displays the flights menu for the shortest path
    */
    void flightDistMenu();

    /** Handles user input in the flights menu for the shortest path
     */
    void flightsDist();

    /** Displays the airports menu
    */
    void airportMenu();

    /** Handles user input in the airports menu
     */
    void airports();

    /** Displays the airlines menu
    */
    void airlineMenu();

    /** Handles user input in the airlines menu
     */
    void airlines();

private:
    Manager manager;
};

#endif
