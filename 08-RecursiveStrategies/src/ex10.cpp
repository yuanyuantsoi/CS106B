/*
 * File: ex10.cpp
 * ------------------------------
 *  The program implements the function listMnemonics.
 */

#include <iostream>
#include <string>
#include "simpio.h"
#include "map.h"
#include "vector.h"
#include "strlib.h"
using namespace std;

/* Function prototypes */

void initializeMap(Map<string, string> & map);
void listMnemonics(string str);
void generateMnemonics(Map<string, string> map, string & str, int index);
string mapNumber(int i);

/* Main program */

int main() {
	string str = getLine("Enter string: ");
	listMnemonics(str);
	return 0;
}

/*
 * Function: listMnemonics
 * Usage: string listMnemonics(str);
 * ------------------------------------------------
 *  The program generates all possible letter combinations
 *  that correspond to a given number, representaed as a string
 *  of digits.
 */

void listMnemonics(string str) {
	Map<string, string> digitMapAlphas;
	initializeMap(digitMapAlphas);
	generateMnemonics(digitMapAlphas, str, 0);
}

/*
 * Function: initializeMap
 * Usage: initializeMap(map);
 * -------------------------------------------------
 *  Initialize map.
 */
void initializeMap(Map<string, string> & map) {
	for (int i = 0; i < 10; i++) {
		string digit = integerToString(i);
		map.put(digit, mapNumber(i));
	}
}


/*
 * Function: mapNumber
 * Usage: string str = mapNumber(i);
 * -----------------------------------------------
 *  A helper function for initializeMap.
 *  The function takes a number as the argument, and
 *  return a string accorading to the number-alpha mapping
 *  on the telephone keypad.
 */

string mapNumber(int i) {
	switch (i) {
		case 2: return "ABC";
		case 3: return "DEF";
		case 4: return "GHI";
		case 5: return "JKL";
		case 6: return "MNO";
		case 7: return "PQRS";
		case 8: return "TUV";
		case 9: return "WXYZ";
		default: return "";
	}
}
			
/*
 * Function: generateMnemonics
 * Usage: generateMnemonics(map, str, index);
 * --------------------------------------------------
 *  The function takes the digt-alpha-map and str and
 *  output the string on the console.
 */
void generateMnemonics(Map<string, string> map, string & str, int index) {
	if (index == str.length()) {
		cout << str << endl;
	} else {
		string key = str.substr(index, 1);
		string alpha = map[key];
		for (int i = 0; i < alpha.length(); i++) {
			str[index] = alpha[i];
			generateMnemonics(map, str, index + 1);
			str[index] = key[0];
		}
	}
}




