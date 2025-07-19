/*
 * File: strlibx.h
 * -------------------------
 *  Extension for strlib.h.
 *  This file exports integerToString & stringToInteger.
 */

#ifndef _strlibx_h
#define _strlibx_h

#include <string>

// Public funcions:
std::string integerToString(int n, int base);
int stringToInteger(std::string str, int base);

// Private functions
std::string integerToStringRec(int n, int base);
char digitToChar(int n);
std::string getSubscript(int base);
int stringToIntegerRec(int soFar, std::string left, int base);
int charToDigit(char ch);

#endif

