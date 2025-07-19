/*
 * File: strlibx.cpp
 * ---------------------------
 *  Same as chapter11 - ex03
 *  This file implements overload versions of
 *  integerToString and stringToInteger functions
 *  that take a second argument indicating the numbric base.
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <cmath>
#include "strlib.h"
#include "error.h"
#include "random.h"
#include "strlibx.h"
using namespace std;

string integerToString(int n, int base) {
    if (n == 0) return "0";
    string signstr = n < 0 ? "-" : "";
    string result = integerToStringRec(abs(n), base);
    return signstr + result;
}

int stringToInteger(string str, int base) {
    int sign = 1; 
    if (str[0] == '-') {
        sign = -1;
        str = str.substr(1);
    }
    return sign * stringToIntegerRec(0, str, base);
}
    
string integerToStringRec(int n, int base) {
    if (n == 0) return "";
    return integerToStringRec(n / base, base) + digitToChar(n % base);
}

char digitToChar(int n) {
    char ch = '?';
    if (n > 36 || n < 0) error("n out of range when changed into char");
    //if (n > 36 || n < 0) error(integerToString(n) + " out of range when changed into char");
    if (n >= 0 && n <= 9) ch = '0' + n;
    if (n >= 10 && n <= 35) ch = 'A' + (n - 10);
        return ch;
}

string getSubscript(int base) {
    string tensDigit = "\u2080";
    tensDigit[tensDigit.size() - 1] += base / 10;
    if ((base / 10) == 0) tensDigit = "";
    string onesDigit = "\u2080";
    onesDigit[onesDigit.size() - 1] += base % 10;
    return tensDigit + onesDigit;
}

int stringToIntegerRec(int soFar, string left, int base) {
    if (left == "") return soFar;
    int digit = charToDigit(left[0]);
    return stringToIntegerRec(soFar * base + digit, left.substr(1), base);
}

int charToDigit(char ch) {
    if (isdigit(ch)) return ch - '0';
    if (isalpha(ch)) return toupper(ch) - 'A' + 10;
    error (string(1, ch) + " cann't be change into digit");
}
