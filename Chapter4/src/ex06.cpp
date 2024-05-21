/*
 * File: ex06.cpp
 * ----------------------------------
 *  This program implements the defaultExtension function that
 *  adds ext to the end of filename.
 */

#include <string>
#include <cctype>
#include <iostream>
#include "simpio.h"
using namespace std;

string defaultExtension(string filename, string ext);

int main() {
	string filename = getLine("Enter filename: ");
	string ext = getLine("Enter ext: ");
	cout << defaultExtension(filename, ext) << endl;
	return 0;
}

string defaultExtension(string filename, string ext) {
	bool force = false;
	if (ext[0] == '*') {
		force = true;
		ext = ext.substr(1);
	}
	
	int dot = filename.find('.', 0);
	if (dot == string::npos) {
		return filename + ext;
	} else if (force) {
		return filename.substr(0, dot) + ext;
	} else {
		return filename;
	}	
}	


