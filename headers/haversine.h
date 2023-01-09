#ifndef LEIC_AM_HAVERSINE_H
#define LEIC_AM_HAVERSINE_H

#include "airport.h"

#include <cmath>

using namespace std;

/** Calculates the distance between two airports using Haversine's Formula
* @param source the source airport
* @param target the target airport
* @return the double value that corresponds to the distance between two airports
*/
double haversine(Airport &source, Airport &target);

/** Calculates the distance between two points on Earth using Haversine's Formula
* @param lat1 the first point's latitude
* @param long1 the first point's longitude
* @param lat2 the second point's latitude
* @param lat2 the second point's longitude
* @return the double value that corresponds to the distance between two points
*/
double haversine(double lat1, double long1, double lat2, double long2);

#endif //LEIC_AM_HAVERSINE_H
