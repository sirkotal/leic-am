#include "../headers/menu.h"
#include "../headers/airport.h"
#include "graph.h"
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
                flightMenu();
                break;
            }

            case 2: {
                cout << endl;
                airportMenu();
                break;
            }

            case 3: {
                cout << endl;
                airlineMenu();
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
}
