#ifndef AIRPORT_H
#define AIRPORT_H

#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

/**
 * A class that represents an airport
 */

class Airport {
    public:
    /** Airport default constructor
    */
    Airport() {};

    /** Airport constructor
    * @param air_code the airport's code
    * @param name the airport's name
    * @param city the airport's city
    * @param country the airport's country
    * @param lat the airport's latitude
    * @param lon the airport's longitude
    */
    Airport(string air_code, string name, string city, string country, double lat, double lon);

    /** Gets the airport's code
    *
    * @return the airport's code
    */
    string getAirCode() const;

    /** Gets the airport's name
    *
    * @return the airport's name
    */
    string getName() const;

    /** Gets the airport's city
    *
    * @return the airport's city
    */
    string getCity() const;

    /** Gets the airport's country
    *
    * @return the airport's country
    */
    string getCountry() const;

    /** Gets the airport's latitude
    *
    * @return the airport's latitude
    */
    double getLatitude() const;

    /** Gets the airport's longitude
    *
    * @return the airport's longitude
    */
    double getLongitude() const;

    bool operator==(const Airport &a2) const;


    private:
        string air_code; /**< The airport's code*/
        string name; /**< The airport's name*/
        string city; /**< The airport's city*/
        string country; /**< The airport's country*/
        double lat; /**< The airport's latitude*/
        double lon; /**< The airport's longitude*/
};

#endif
