#ifndef LEIC_AM_HAVERSINE_H
#define LEIC_AM_HAVERSINE_H

#include "airport.h"

#include <cmath>

using namespace std;

double haversine(Airport &source, Airport &target);
double haversine(double lat1, double long1, double lat2, double long2);

#endif //LEIC_AM_HAVERSINE_H
