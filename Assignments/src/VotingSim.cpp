/*
 * File: VotingSim.cpp
 * -------------------
 *  This program simulates an voting process with centrain error rate, then performs 500 simulation trials 
 *  and record the ratio below.
 *  Ratio:
 *  		number of trials in which election result was invalid
 *  		——————————————————————————————————————————————————————
 *  		            total number of trials
 *
 *  The voting simulation parameters:
 *  	1. the number of voters
 *  	2. percentage spread between candidates
 *  	3. voting error percentage
 *  will be entered by user.
 */


#include <iostream>
#include "error.h"
#include "random.h"
#include "simpio.h"
using namespace std;

const int NUM_TRIALS = 500;

/* Function prototypes */
bool errorOccur(double errRate);
bool runOneTrial(int nVoters, double pct, double errRate);



/* Main function */

int main() {
	int numVoters = getInteger("Enter number of voters: ");
	double pctSpread = getReal("Enter percentage spread between candidates: ");
	double errRate = getReal("Enter voting error percentage: ");

	int invalidRun = 0;
	for (int i = 0; i < NUM_TRIALS; i++) {
		if (!runOneTrial(numVoters, pctSpread, errRate)) invalidRun++;
	}

	double pctOfInvalid = double (invalidRun) / NUM_TRIALS;
	cout << endl;
	cout << "Chance of an invalid election result after " << NUM_TRIALS << " trials = " << pctOfInvalid << endl;
	
	return 0;
}

/*
 * Function: runOneTrial
 * Usage: if (runOneTrial1( nVoters, pct, errRate);
 * --------------------------------------------------
 *  The voters number are dertemined by the pct spread abs.
 */
bool runOneTrial(int nVoters, double pct, double errRate) {
	int winner = nVoters * (0.5 + pct);
	int loser = nVoters * (0.5 - pct);
	
	int voterCountW = 0;
	int voterCountL = 0;
	// People who intends to vote for winner.
	for (int i = 0; i < winner; i++) {
		if(errorOccur(errRate)) voterCountL++;
		else voterCountW++;
	}

	// People who intends to vote for loser.
	for (int i = 0; i < loser; i++) {
		if (errorOccur(errRate)) voterCountW++;
		else voterCountL++;
	}

	return voterCountW > voterCountL;
}




/*
 * Function: errprOccur(double)
 * usage: if( errorOccur(errRate));
 * ------------------------------------
 *  Simulates the voting maching with centrain error rate, returns the result.
 */

bool errorOccur(double errRate) {
	return randomChance(errRate);
}
