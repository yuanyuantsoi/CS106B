/*
 * File: ex02.cpp
 * --------------------------------------
 *  This program computes the wind chill for a given temperature and wind
 *  velocity, and displays these values in tabular form.
 */

#include <cmath>
#include <iomanip>
#include <string>
#include <iostream>
using namespace std;

const int COMLUMN_WIDTH = 5;

int main() {
	cout << setw(COMLUMN_WIDTH * 5) << " " << " Temperature (F) " << setw(COMLUMN_WIDTH * 5) << " " << endl;
	
	cout << left << setw(COMLUMN_WIDTH) << "Calm";
	for (int temp = 40; temp >= -40; temp -= 5)
		cout << left << setw(COMLUMN_WIDTH) << temp; 
	
	cout << endl;

	for (int windV = 5; windV <= 60; windV += 5) {
		cout << setw(COMLUMN_WIDTH) << windV;
		for (int temp = 40; temp >= -40; temp -= 5) {
			double windChill = 35.74 + 0.6215 * temp - 35.75 * pow(windV, 0.16) + 0.4275 * temp * pow(windV, 0.16);
			cout << left << setw(COMLUMN_WIDTH) << fixed << setprecision(0) << windChill;
		}
		cout << endl;
	}
	return 0;
}
