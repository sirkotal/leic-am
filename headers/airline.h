#ifndef AIRLINE_H
#define AIRLINE_H

#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;
/**
 * A class that represents an airline
 */
class Airline {
    public:
    /** Airline default constructor
    */
    Airline();

    /** Airline constructor
    * @param code the airline's code
    * @param name the airline's name
    * @param callsign the airline's callsign
    * @param country the airline's country
    */
    Airline(string code, string name, string callsign, string country);

    /** Gets the airline's code
    *
    * @return the airline's code
    */
    string getCode() const;

    /** Gets the airline's name
    *
    * @return the airline's name
    */
    string getName() const;

    /** Gets the airline's call sign
    *
    * @return the airline's call sign
    */
    string getCallsign() const;

    /** Gets the airline's country
    *
    * @return the airline's country
    */
    string getCountry() const;

    bool operator==(const Airline &al2) const;


    private:
        string code; /**< The airline's code*/
        string name; /**< The airline's name*/
        string callsign; /**< The airline's call sign*/
        string country; /**< The airline's country*/
};

#endif
