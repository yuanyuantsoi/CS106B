/*
 * File: ex17.cpp
 * ----------------------------
 *  This program implements the function encodeCaesarCipher
 *  that return a new string.
 */

#include <string>
#include <cctype>
#include <iostream>
#include "simpio.h"
using namespace std;

char encodeLetter(char ch, int shift);
string encodeCaesarCipher(string str, int shift);

int main() {
	cout << "This program encodes a message using a Caesar cipher." << endl;
	int shift = getInteger("Enter the number of character position to shift: ");
	string str = getLine("Enter a message: ");
	cout << "Encoded message: " << encodeCaesarCipher(str, shift) << endl;
	return 0;
}

string encodeCaesarCipher(string str, int shift) {
	string encodeStr = "";
	for (int i = 0; i < str.length(); i++) {
		char ch = str[i];
		encodeStr += encodeLetter(ch, shift);
	}
	return encodeStr;
}

char encodeLetter(char ch, int shift) {
	if (!isalpha(ch)) return ch;
	char base = isupper(ch) ? 'A' : 'a';
	return (ch - base + shift) % 26 + base;
}
