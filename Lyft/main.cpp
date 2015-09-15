#include "lyft.h"

int main (int argc, char* argv[]) {

	cout << "Compute Haversine: " << endl;

	pair<double, double> d1, d2;

	aStart = make_pair(-77.037852*M_PI/180, 38.898556*M_PI/180);
	aDest = make_pair(-77.043934*M_PI/180, 38.897147*M_PI/180);
	bStart = make_pair();
	bDest = make_pair();

	double aDist, bDist, shortest;

	aDist = haversine(aStart, aDest);

	bDist = haversine(bStart, bDest);

	cout << "Minimum detour route: ";

	if(aDist > bDist) {
		cout << "A -> C -> D -> B" << endl;
	}
	else if(aDist == bDist) {
		cout << "Both are same" << res << endl;
	}
	else {
		cout << "C -> A -> B -> D" << endl;
	}

	return 0;
}