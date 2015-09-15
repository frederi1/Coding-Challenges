#include "lyft.h"

double haversine (pair<double, double> driverA, pair<double, double> driverB) {
	double dLon, dLat, a, c, d;
	
	dLon = driverA.first - driverB.first; 
	dLat = driverA.second - driverB.second; 
	
	a = pow( sin(dLat/2), 2) + cos(driverA.second) * cos(driverB.second) * pow(sin(dLon/2), 2); 
	
	c = 2 * atan2(sqrt(a), sqrt(1 - a));
	
	d = 6373000 * c;

	return d;
}

double minimum_tour (vector<pair<point, point>>) {
	string path;


	return make_pair(d, path);
}