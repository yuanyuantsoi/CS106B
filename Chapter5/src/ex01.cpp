/*
 * File: ex01.cpp
 * --------------------------------------------
 *  This program writes the readVector() function;
 */
#include <iomanip>
#include <iostream>
#include <string>
#include <cctype>
#include "filelib.h"
#include "simpio.h"
#include <fstream>
#include "vector.h"
using namespace std;

void readVector(istream & is, Vector<int> & vec);
void readVector(istream & is, Vector<double> & vec);
void readVector(istream & is, Vector<string> & vec);

int main() {
	ifstream infile;
	promptUserForFile(infile, "Input file: ");
	Vector<double> roots;
	for (int i = 0; i < 3; i++) {
		cout << "Read file " <<  i + 1 << " times." << endl;
		readVector(infile, roots);
		cout << "Print vec: " << endl;
		for (int i = 0; i < roots.size(); i++) 
			cout << fixed << setprecision(4) << roots[i] << endl;
		cout << "End of Vec." << endl;
		cout << endl;
	}
	return 0;
}

void readVector(istream & is, Vector<double> & vec) {
	vec.clear();
	string line;
	while (getline(is, line)) {
		if (line == "") break;
		istringstream stream(line);
		double value;
		stream >> value >> ws;
		vec.add(value);
	}
	return;
}

void readVector(istream & is, Vector<int> & vec) {
	vec.clear();
	string line;
	while (getline(is, line)) {
		if (line == "") break;
		istringstream stream(line);
		int value;
		stream >> value >> ws;
		vec.add(value);
	}
	return;
}

void readVector(istream & is, Vector<string> & vec) {
	vec.clear();
	string line;
	while (getline(is, line)) {
		if (line == "") break;
		vec.add(line);
	}
	return;
}
