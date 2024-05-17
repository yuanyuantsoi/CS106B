/*
 * File: ex10.cpp
 * -------------------------------------------------------
 * This program implements a function replaceAll that returns 
 * a copy of str with every occurrence of c1 replaced by c2.
 */

#include <iostream>
#include <string>
#include <cctype>
#include "simpio.h"
using namespace std;

string replaceAll(string str, char c1, char c2);
string replaceAll(string str, string s1, string s2);

int main() {
	string str = getLine("Enter string: ");
/*
	char c1, c2;
	cout << "Enter char c1: ";
	cin >> c1;
	cout << "Enter char c2: ";
	cin >> c2;
	cout << endl;
	cout << replaceAll(str, c1, c2) << endl;
*/	
	string s1, s2;
	
	cout << "Enter s1: ";
	getline(cin, s1);
	
 	cout << endl;

	cout << "Enter s2: ";
	getline(cin, s2);
	
	
	cout << replaceAll(str, s1, s2) << endl;
	return 0;
}

string replaceAll(string str, char c1, char c2) {
	string result = "";
	for (int i = 0; i < str.length(); i++) {
		if (c1 == str[i]) result += c2;
		else result += str[i];
	}
	return result;
}

string replaceAll(string str, string s1, string s2) {
	int found = 0;
	while ((found = str.find(s1, found)) != string::npos) {
		str.replace(found, s1.length(), s2);
	}
	return str;
}
