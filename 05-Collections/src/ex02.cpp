/*
 * File: ex02.cpp
 * --------------------------------------------
 *  This program implements the function mean that returns
 *  the mean of the data in the vector.
 */

#include <string>
#include <iostream>
#include <cctype>
#include "simpio.h"
#include "vector.h"
#include <cmath>
using namespace std;

double mean(Vector<double> & data);
double stddev(Vector<double> & data);

int main() {
	Vector<double>  data;
	while (true) {
		double value = getReal(" ? ");
		if (value == 0) break;
		data.add(value);
	}
	double ave = mean(data);
	cout << "Mean is " << ave << endl;
	
	double stddevNum = stddev(data);
	cout << "stddev is " << stddevNum << endl;
	return 0;
}

double mean(Vector<double> & data) {
	double total = 0;
	for (int i = 0; i < data.size(); i++) {
		total += data[i];
	}
	return total / data.size();
}


double stddev(Vector<double> & data) {
	double ave = mean(data);
	double sum = 0;
	for (int i = 0; i < data.size(); i++) {
		sum += pow((data[i] - ave), 2);
	}
	double result = sqrt(sum / data.size());
	return result;
}
