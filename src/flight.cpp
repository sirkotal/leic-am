#include "../headers/flight.h"

Flight::Flight(string source, string target, string airline) {
    this->source = source;
    this->target = target;
    this->airline = airline;
}

string Flight::getSource() const{
    return source;
}

string Flight::getTarget() const {
    return target;
}

string Flight::getAirline() const {
    return airline;
}