/*
 * File: ex12.cpp
 * ------------------------------
 *  The program implements the function listCompletions.
 */

#include <iostream>
#include <string>
#include "simpio.h"
#include "map.h"
#include "vector.h"
#include "strlib.h"
#include "lexicon.h"
#include "set.h"
using namespace std;

/* Function prototypes */

void initializeMap(Map<string, string> & map);
void listCompletions(string digits, Lexicon & lex);
void generatePrefix(Map<string, string> map, string & str, int index, Lexicon & lex, Set<string> & prefix);
void generateCompletions(Lexicon & lex, Set<string> & prefix);
string mapNumber(int i);
void prefixToWord(Lexicon & lex, string prefix);

/* Main program */

int main() {
	string str = getLine("Enter string: ");
	Lexicon english("EnglishWords.dat");
	listCompletions(str, english);
	return 0;
}

/*
 * Function: listCompletions
 * Usage: listCompletions(str);
 * ------------------------------------------------
 *  The program generates all possible letter combinations
 *  that correspond to a given number, representaed as a string
 *  of digits.
 */

void listCompletions(string digits, Lexicon & lex) {
	Map<string, string> digitMapAlphas;
	initializeMap(digitMapAlphas);
	Set<string> prefix;
       	generatePrefix(digitMapAlphas, digits, 0, lex, prefix);
	generateCompletions(lex, prefix);
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
 * Function: generatePrefix
 * Usage: generatePrefix(map, str, index);
 * --------------------------------------------------
 *  The function takes the digt-alpha-map and str and
 *  output the string on the console.
 */
void generatePrefix(Map<string, string> map, string & str, int index, Lexicon & lex, Set<string> & prefix) {
	if (index == str.length()) {
		if (lex.contains(str) || lex.containsPrefix(str)) prefix.add(str); //更简洁的实现方式应该在这里调用函数补全单词，减少重复判断
	} else {
		string key = str.substr(index, 1);
		string alpha = map[key];
		for (int i = 0; i < alpha.length(); i++) {
			str[index] = alpha[i];
			generatePrefix(map, str, index + 1, lex, prefix);
			str[index] = key[0]; //CRITICAL LINE
		}
	}
}

/*
 * Function: gernerateCompletions
 * Usage: generateCompletions(lex, prefix);
 * -------------------------------------------------
 *  Prints all words that from the lexicon that can 
 *  be formed by extending the given prefix.
 */
void generateCompletions(Lexicon & lex, Set<string> & prefix) {
	for (string s : prefix) {
		prefixToWord(lex, s);
	}
}

/*
 * Function: prefixToWrod
 * Usage: prefixToWord(prefix);
 * ----------------------------------------------
 *  Output the word;
 */

void prefixToWord(Lexicon & lex, string prefix) {
	if (lex.contains(prefix)) {
		cout << prefix << endl;
	} else if (lex.containsPrefix(prefix)) {
		for (char ch = 'a'; ch <= 'z'; ch++) {
			prefixToWord(lex, prefix + ch);
		}
	}
}


