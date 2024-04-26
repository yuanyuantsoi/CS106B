#include <iostream>
#include <cstdlib>
#include <string>
#include "error.h"
using namespace std;

void error(string msg) {
	cerr << msg << endl;
	exit(EXIT_FAILURE);
}
