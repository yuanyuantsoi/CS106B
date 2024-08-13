/*
 * File: ex18.cpp
 * --------------------------------------
 *  This program implements a letter-substitution cipher.
 */

#include <iostream>
#include <string>
#include <cctype>
#include "simpio.h"
using namespace std;

char encodeCharacter(char ch, string key);
string encodeLettersubCipher(string msg, string key);

int main() {
	cout << "Letter substitution cipher" << endl;
	string key = getLine("Enter a 26-Letter key: ");
	string msg = getLine("Enter a message: ");
	cout << "Encoded message: " << encodeLettersubCipher(msg, key) << endl;
	return 0;
}

string encodeLettersubCipher(string msg, string key) {
	string encodeMsg;
	for (int i = 0; i < msg.length(); i++) {
		encodeMsg += encodeCharacter(msg[i], key);
	}
	return encodeMsg;
}

char encodeCharacter(char ch, string key) {
	if (!isalpha(ch)) return ch;
	return key[(toupper(ch) -'A')];
}
