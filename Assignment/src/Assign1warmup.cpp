/*
 * Program: warmup.cpp
 * --------------------
 * Program used to generate a hash code based on user's name.
 * As given, this code has two compiler errors you need to track down 
 * and fix in order to get the program up and running.
 *
 * jzelenski Thu Apr  1 12:27:53 PST 2004
 */

#include <iostream>
#include <string>
#include "simpio.h"
using namespace std;

#define MAX_HASH_CODE	10000	// Upper bound for hash codes generated by program

/* Function prototypes */

int Hash(string s, int maxCode);


/*
 * Function: Hash
 * Usage: hash_number = Hash(key, max_hash);
 * -----------------------------------------
 * This function takes the key and uses it to derive a hash code,
 * which is an integer in the range [0, maxCode - 1].  The hash
 * code is computed using a method called linear congruence.
 */
#define Multiplier -1664117991L		// Multiplier used in Hash function

int Hash(string s, int maxCode)
{
    unsigned long hashcode = 0;
    for (int i = 0; i < s.length(); i++) 
        hashcode = hashcode * Multiplier + s[i];
   return (hashcode % maxCode);
}

int main ()
{
	cout << "Please enter your name: ";
	string name = getLine();
	
	int hashcode = Hash(name, MAX_HASH_CODE);
	cout << "The hash code for your name is " << hashcode << "." <<endl;

	return 0;
}
