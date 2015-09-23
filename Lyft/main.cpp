#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

typedef pair<double, double> point;

double haversine (point pt1, point pt2);

int main (int argc, char* argv[]) {

	cout << "Compute Haversine: " << endl;

	point aStart, bStart, aDest, bDest;

	// (A, B) start, dest for driver A
	// (C, D) start, dest for driver B

	aStart = make_pair(-77.037852, 38.898556);
	aDest = make_pair(-77.043934, 38.897147);
	bStart = make_pair(-18.2945, 29.18693);
	bDest = make_pair(-17.049281, -29.18239);

	double aDist, bDist, shortest, res;

	// Calculate distances for drivers' to get from start to finish

	aDist = haversine(aStart, aDest);

	bDist = haversine(bStart, bDest);

	cout << "Minimum detour route: ";

	// Two possible tours: ACDB or CABD 

	res = haversine(aStart, bStart) + haversine(bStart, bDest) + haversine(bDest, aDest) + haversine(aStart, aDest);

	if(aDist > bDist) {
		res -= aDist;
		cout << "A -> C -> D -> B" << endl;
	}
	else if(aDist == bDist) {
		res -= aDist;
		cout << "Both are same" << endl;
	}
	else {
		res -= bDist;
		cout << "C -> A -> B -> D" << endl;
	}



	cout << "Distance is: " << res << endl;

	return 0;
}

double haversine (point pt1, point pt2) {
	
	double dLon, dLat, a, c, d;

	point pt1Rad, pt2Rad;

	pt1Rad = make_pair(pt1.first*M_PI/180, pt1.second*M_PI/180);

	pt2Rad = make_pair(pt2.first*M_PI/180, pt2.second*M_PI/180);

	dLon = pt1Rad.first - pt2Rad.first; 
	dLat = pt1Rad.second - pt2Rad.second; 
	
	a = pow( sin(dLat/2), 2) + cos(pt1Rad.second) * cos(pt2Rad.second) * pow(sin(dLon/2), 2); 
	
	c = 2 * atan2(sqrt(a), sqrt(1 - a));
	
	d = abs(6373000 * c);

	return d;
}