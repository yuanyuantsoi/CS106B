#include <iostream>
#include "vector.h"
using namespace std;

int cutStock(Vector<int> & requests, int stockLength);
int recCutStock(int & nPipes, Vector<int> & requests, int stockLength);
bool foundMaxLessThan(int max, Vector<int> & requests);

int main() {
	Vector<int> requests;
    // Test case
    requests += 4, 3, 4, 1, 7, 8;
	int minNumPipes = cutStock(requests, 10);
	cout << "Mini number of stock pipes = " << minNumPipes << endl;
	return 0;
}


int cutStock(Vector<int> & requests, int stockLength) {
	int nPipes = 0;
	recCutStock(nPipes, requests, stockLength);
	return nPipes;
}

int recCutStock(int & nPipes, Vector<int> & requests, int stockLength) { 
	// Simple case
    if (requests.isEmpty()) return 0;
    
    // New pipe
    // Add first request to the pipe
    cout << "pipe " << ++nPipes << ": " << requests[0];
	int remain = stockLength - requests[0];
	requests.remove(0);
	
    // Find max request less than the remain of the pipe
    int found = 0;
	while ((found = foundMaxLessThan(remain, requests) != -1) {
		remain -= requests[index];
		cout << ", " << requests[index];
		requests.remove(index);
	}
	cout << endl;
	recCutStock(nPipes, requests, stockLength);
    return nPipes;
}	


int foundMaxLessThan(int max, Vector<int> & requests) {
    int index = 0;
	for (int i = 0; i < requests.size(); i++) {
		if (requests[i] <= max && requests[i] >= requests[index]) {
			index = i;
		}
	}
	return found;
}
