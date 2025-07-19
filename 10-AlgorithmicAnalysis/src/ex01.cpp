/*
 * File: ex01.cpp
 * -------------------------------
 *  Chapter10 - ex01 
 *  This file implements the raiseToPower function that
 *  runs in O(logN)time.
 */
#include <iostream>
#include "simpio.h"
using namespace std;

double raiseToPower(double x, int n);

int main() {
    double x = getReal("Enter x = ");
    int n = getInteger("Enter n = ");
    cout << x << "^" << n << " = " << raiseToPower(x, n) << endl;
    return 0;
}

double raiseToPower(double x, int n) {
    if (n == 0) return 1.0;
    if (n == 1) return x;
    // x^n = x^(n/2) * x^(n/2) * x^(n%2)
    // set x^(n/2) as evenPart
    // set x^(n%2) as oddPart
    double evenPart = raiseToPower(x, n / 2);
    double oddPart = raiseToPower(x, n % 2);
    return oddPart * evenPart * evenPart;
}
