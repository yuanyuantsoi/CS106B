/*
 * File: ex20.cpp
 * ----------------------------------
 *  This program implements a function that returns the first position at which
 *  DNA strand s1 can attach to the strand s2.
 */

#include <iostream>
#include <string>
#include <cctype>
#include "simpio.h"
#include "error.h"
using namespace std;

int findDNAMatch(string s1, string s2, int start = 0);
char matchBase(char ch);


int main() {
	string s1 = getLine("Enter s1(short): ");
	string s2 = getLine("Enter s2(long): ");
	int n = getInteger("Enter the position at with the search should start: ");
	cout << findDNAMatch(s1, s2, n) << endl;
	return 0;
}


int findDNAMatch(string s1, string s2, int start) {
	string match = "";
	for (int i = 0; i < s1.length(); i++) {
		match += matchBase(s1[i]);
	}
	int found;
	if ((found = s2.find(match, start)) == string::npos) found = -1;
	return found;
}

char matchBase(char ch) {
	switch (toupper(ch)) {
		case 'C': return 'G';
		case 'G': return 'C';
		case 'A': return 'T';
		case 'T': return 'A';
		default: error("Illegal DNA base. ");
	}
}
