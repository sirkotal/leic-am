#include "../headers/airline.h"

Airline::Airline(string code, string name, string callsign, string country) {
    this->code = code;
    this->name = name;
    this->callsign = callsign;
    this->country = country;
}

string Airline::getCode() const {
    return code;
}

string Airline::getName() const {
    return name;
}

string Airline::getCallsign() const {
    return callsign;
}

string Airline::getCountry() const {
    return country;
}