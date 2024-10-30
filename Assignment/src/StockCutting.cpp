/*
 * File: StockCutting.cpp
 * -----------------------------------------
 *  The program solve the problem of the kind that needs
 *  minimizing the consuption of a scarce resource.
 */

#include <iostream>
#include "simpio.h"
#include "vector.h"
using namespace std;

/* Function prototype */

int cutStock(Vector<int> & requests, int stockLength);
void recCutStock(Vector<int> requests, int stockLength, Vector< Vector<int> > & solutions);
int findMaxLessThan(int limit, Vector<int> & vec);
void displaySolution(Vector< Vector<int> > & jaggedArray);

/* Main program */

int main() {
	Vector<int> requests;
	requests += 4, 3, 4, 1, 7, 8;
	cutStock(requests, 10);
	return 0;
}

/*
 * Function: cutStock
 * Usage: int n = cutStock(requests, stockLength);
 * --------------------------------------------------
 * Given a vector of lengths needed and stocklength, 
 * return the minimum number of stock pipes needed 
 * to service all requests in the vector.
 * This is a warpper function for recCutStock.
 */
int cutStock(Vector<int> & requests, int stockLength) {
	Vector< Vector<int> > solutions;
	recCutStock(requests, stockLength, solutions);
	displaySolution(solutions);
	return solutions.size();
}

/*
 * Function: recCutStock
 * Usage: recCutStock(requests, stockLength, solutions);
 * --------------------------------------------------------
 *  This funciton does all the hard work for cutStock.
 *  The problem is solved using the followed steps:
 *  	1. grab a box
 *  	2. put the first request into the box
 *  	3. find out the larggest item that could fit into the box
 *  	while less than the remnants of the box
 *  	4. put the found item into the box, and remove it from requests
 *  	5. repeat 3-4 until non found or the box if full
 *  	6. go to the next request
 *  	...
 *  	return when there is no request.
 */
void recCutStock(Vector<int> requests, int stockLength, Vector< Vector<int> > & solutions) {
	if (requests.isEmpty()) return;
	
	//put the first requests into the box
	Vector<int> box;
	box.add(requests[0]);
	int remnants = stockLength - requests[0];
	requests.remove(0);

	int found;
	while ((found = findMaxLessThan(remnants, requests)) != -1 && remnants != 0) {
		remnants -= requests[found];
		box.add(requests[found]);
		requests.remove(found);
	}
	
	solutions.add(box);
	recCutStock(requests, stockLength, solutions);
}


/*
 * Function: findMaxLessThan
 * Usage: int n = findMaxLessThan(limit, vec);
 * -------------------------------------------------
 *  Found out the max num that is less than(or equal) the limit. 
 *  Return its index. Return -1 when found non.
 */
int findMaxLessThan(int limit, Vector<int> & vec) {
	int found = -1;
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i] <= limit) {
			if (found == -1 || vec[i] > vec[found]) found = i;
		}
	}
	return found;
}
			
void displaySolution(Vector< Vector<int> > & jaggedArray) {
	for (int i = 0; i < jaggedArray.size(); i++) {
		for (int j = 0; j < jaggedArray[i].size(); j++) {
			if (j != 0) cout << ", ";
			cout << jaggedArray[i][j];
		}
		cout << endl;
	}
	cout << endl;
}
