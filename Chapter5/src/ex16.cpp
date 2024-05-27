/*
 * File: ex16.cpp
 * -----------------
 *  This program addes an extension to CheckoutLine simulation, which rewrite
 *  the simulation so that there are several lindependent queues, as is usually
 *  the case in supermarkets. New customers finds the shortest line and enter that
 *  queue.
 */

#include <iostream>
#include <iomanip>
#include "queue.h"
#include "vector.h"
#include "simpio.h"
#include "random.h"
using namespace std;

/* Constants */

const int SIMULATION_TIME = 2000;
const double ARRIVAL_PROBABILITY = 0.05;
const int MIN_SERVICE_TIME = 5;
const int MAX_SERVICE_TIME = 15;
const int TOTAL_CASHIER_LINES = 4;

/* Function prototypes */

void runSimulation(int & nServed, int & totalWait, int & totalLength);
void printReport(int nServed, int totalWait, int totalLength);
int findShortestQueue(Vector< Queue<int> > & queVec);

/* Main program */

int main() {
	int nServed;
	int totalWait;
	int totalLength;
	runSimulation(nServed, totalWait, totalLength);
	printReport(nServed, totalWait, totalLength);
	return 0;
}

void  runSimulation(int & nServed, int & totalWait, int & totalLength) {
	nServed = 0;
	totalWait  = 0;
	totalLength = 0;
	
	Queue<int> queue0;
	Queue<int> queue1;
	Queue<int> queue2;
	Queue<int> queue3;
	Vector< Queue<int> > cashierLine(TOTAL_CASHIER_LINES);
	cashierLine[0] = queue0;
	cashierLine[1] = queue1;
	cashierLine[2] = queue2;
	cashierLine[3] = queue3;
	
	Vector<int> timeRemaining(TOTAL_CASHIER_LINES);
	
	for (int t = 0; t < SIMULATION_TIME; t++) {
		if (randomChance(ARRIVAL_PROBABILITY)) {
			int shortestQueIndex = findShortestQueue(cashierLine);
			cashierLine[shortestQueIndex].enqueue(t);
		}

		// Serve customer
		for (int i = 0; i < TOTAL_CASHIER_LINES; i++) {
			if (timeRemaining[i] > 0) {
				timeRemaining[i]--;
			} else if (!cashierLine[i].isEmpty()) {
				totalWait += t - cashierLine[i].dequeue();
				nServed++;
				timeRemaining[i] = randomInteger(MIN_SERVICE_TIME, MAX_SERVICE_TIME);
			}
		}
		for (int i = 0; i < TOTAL_CASHIER_LINES; i++) {
			totalLength += cashierLine[i].size();
		}

	}
	return;
}

int findShortestQueue(Vector< Queue<int> > & queVec) {
	int shortest = 0;
	for (int i = 1; i < queVec.size(); i++) {
		if (queVec[shortest].size() > queVec[i].size()) shortest = i;
	}
	return shortest;
}

void printReport(int nServed, int totalWait, int totalLength) {
	cout << "Simulation results given the following constants: " << endl;
	cout << fixed << setprecision(2);
	cout << " SIMULATION_TIME:  " << setw(4) << SIMULATION_TIME << endl;
	cout << " ARRIVAL_PROBABILITY: " << setw(4) << ARRIVAL_PROBABILITY << endl;
	cout << " MIN_SERVICE_TIME: " << setw(4) << MIN_SERVICE_TIME << endl;
	cout << " MAX_SERVICE_TIME: " << setw(4) << MAX_SERVICE_TIME << endl;
	cout << endl;
	cout << " Customers served:  " << setw(4) << nServed << endl;
	cout << " Average waiting time: " << setw(7) << double(totalWait) / nServed << " seconds " << endl;
	cout << " Average queue length: " << setw(7) << double(totalLength) / SIMULATION_TIME << " people" << endl;
}
