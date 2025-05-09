#include <iostream>
#include <fstream>
#include <string>
#include "sound.h"
using namespace std;

int main() {
	Sound test("not.wav");
	test.play();
	return 0;
}
