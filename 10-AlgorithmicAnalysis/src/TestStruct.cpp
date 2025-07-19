/*
 * File: TestStruct.cpp
 * ----------------------------------------
 *  Used to test struct for operator overload.
 */

#include <iostream>
#include <string>
using namespace std;

struct report{
    string str;
};

ostream & operator<<(ostream & os, const report & rt) {
    os << rt.str;
    return os;
}

int main() {
    report warning;
    warning.str = " stop ";
    cout << warning << endl;
    return 0;
}
