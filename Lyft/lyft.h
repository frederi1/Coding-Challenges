#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

typedef pair<double, double> point;

double haversine (pair<double, double> driverA, pair<double, double> driverB);

double minimum_tour (vector<pair<point, point>>);
