/*
 * File: CityMap.cpp
 * -------------------------------------------
 *  The program is used to manipulate a geographic map
 *  of major world cities. When the user clicks on a 
 *  point, the program would report what city is here.
 */

#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
#include "simpio.h"
#include "strlib.h"
#include "vector.h"
#include "map.h"
using namespace std;

struct pointT {
	int x, y;
};

struct cityT {
	string name;
	pointT coordinates;
};

/* Function prototypes */

string pointTToString(pointT point);

/* Main program */

int main() {
	Vector<cityT> cities;
       cityT beijing = {"Beijing", {0,0}};
       cities.add(beijing);
       cityT SH = {"Shanghai", {1, 0}};
       cities.add(SH);

       Map<string, string> cityMap;
       for (cityT city : cities) {
	       string key = pointTToString(city.coordinates);
	       cityMap[key] = city.name;
       }
       for (string key : cityMap) {
	       cout << setw(10) << left << key << right << cityMap[key] << endl;
       }
       pointT point = {0, 0};
       cout << cityMap[pointTToString(point)] << endl;
	return 0;
}

/*
 * Function: pointTToString
 * Usage: string str = pointTToString(point);
 * -------------------------------------------
 *  The function takes a point returns a string version
 *  of point.
 */
string pointTToString(pointT point) {
	return "(" + integerToString(point.x) + ", " + integerToString(point.y) + ")";
}
