/*
 * File: ex12.cpp
 * ----------------------------------
 *  This file implements the fib(n) that runs in O(logN) time.
 */

#include <iostream>
#include <cmath>
using namespace std;

double fib(int n);
double power(double x, int n);
double getPhi();
double getPsi();

int main() {
    for (int i = 0; i < 100; i++) {
        cout << "fib(" << i << ") = " << fixed << fib(i) << endl;
    }
    return 0;
}

double fib (int n) {
    return ((power(getPhi(), n) - power(getPsi(), n)) / sqrt(5));
}

double power(double x, int n) {
    if (n == 0) return 1;
    if (n == 1) return x;
    double oddpart = power(x, n % 2);
    double evenpart = power(x, n / 2);
    return oddpart * evenpart * evenpart;
}

double getPhi(){
    return (1 + sqrt(5)) * 1.0 / 2;
}

double getPsi() {
    return (1 - sqrt(5)) * 1.0 / 2;
}
