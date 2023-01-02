#include "../headers/airport.h"

Airport::Airport(string air_code, string name, string city, string country, double lat, double lon) {
    this->air_code = air_code;
    this->name = name;
    this->city = city;
    this->country = country;
    this->lat = lat;
    this->lon = lon;
}

string Airport::getAirCode() const{
    return air_code;
}

string Airport::getName() const {
    return name;
}

string Airport::getCity() const {
    return city;
}

string Airport::getCountry() const {
    return country;
}

double Airport::getLatitude() const {
    return lat;
}

double Airport::getLongitude() const {
    return lon;
}

bool Airport::operator==(const Airport &a2) const {
    return air_code == a2.getAirCode();
}
