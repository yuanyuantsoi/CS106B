/*
 * File: EveryVoteCounts.cpp
 * ----------------------------------------------
 *  H18 - Assign3RecPS
 *  problem 3 - EveryVoteCounts
 *  The problem computes the number of critical votes
 *  per block due to the block-voting system used in American
 *  presidential election.
 */

#include <iostream>
#include "vector.h"
using namespace std;

/* Function prototypes */

int countCriticalVotes(Vector<int> & blocks, int blockIndex);
void recCount(int aliceVoteCount, int bobVoteCount, Vector<int> & blocks, int currentIndex, int targetIndex, int & numCriticalVotes);
bool isCriticalVote(int numAVotes, int numBVotes, int numVotes);
int intPow(int base, int exp);

/* Main program */

int main() {
	Vector<int> blocks;
	blocks += 4, 2, 7, 4;

	Vector<int> blocks2;
	blocks2 += 9, 9, 7, 3, 1, 1;

	for (int i = 0; i < blocks2.size(); i++) {
		cout << " The " << i << "th block is critical in " 
			<< countCriticalVotes(blocks2, i) << " of the "
			<< intPow(2, blocks2.size() - 1) << " possible situations. " << endl;
	}
	return 0;
}

/*
 * Function: countCriticalVotes
 * Usage: int n = countCriticalVotes(blocks, blockIndex);
 * --------------------------------------------------------------------
 *  Warpper funciton of recCount.
 *  Return the number of critical votes of a certain block indicated by blockIndex in blocks.
 */
int countCriticalVotes(Vector<int> & blocks, int blockIndex) {
	int numCriticalVotes = 0;
	recCount(0, 0, blocks, 0, blockIndex, numCriticalVotes);
	return numCriticalVotes;
}

/*
 * Function: recCount
 * Usage: recCount(aliceVoteCount, bobVoteCount, blocks, currentIndex, targetIndex, numCriticalVotes);
 * ----------------------------------------------------------------------------------------------------
 *  Finds out critical votes of the target block.
 *  Assume there are two candidate: Alice and Bob.
 *  First, compute their total votes repesptively except for the target block, 
 *  Second, find out whther or not the target block'vote is critical. 
 */
void recCount(int aliceVoteCount, int bobVoteCount, Vector<int> & blocks, int currentIndex, int targetIndex, int & numCriticalVotes) {
	if (currentIndex == targetIndex) currentIndex++;
	if (currentIndex == blocks.size()) {
		if (isCriticalVote(aliceVoteCount, bobVoteCount, blocks[targetIndex])) numCriticalVotes++;
		return;
	}

	// Current block vote for Alice
	recCount(aliceVoteCount + blocks[currentIndex], bobVoteCount, blocks, currentIndex + 1, targetIndex, numCriticalVotes);
	
	// Current block vote for Bob
	recCount(aliceVoteCount, bobVoteCount + blocks[currentIndex], blocks, currentIndex + 1, targetIndex, numCriticalVotes);
}

/*
 * Function: isCriticalVote
 * Usage: if (isCriticalVote(numAVotes, numBVotes, numVotes))
 * -------------------------------------------------------------
 *  If candidate A has numAVotes, candidate B has numBVotes, return true
 *  if the choice of numVotes will force the win for that candidate, 
 *  false otherwise.
 */
bool isCriticalVote(int numAVotes, int numBVotes, int numVotes) {
	if (numAVotes == numBVotes) return true;
	if (numAVotes < numBVotes && ((numAVotes + numVotes) > numBVotes)) return true;
	if (numAVotes > numBVotes && (numAVotes < (numBVotes + numVotes))) return true;
	return false;
}

/*
 * Function: intPow
 * Usage: int n = intPow(base, exp);
 * --------------------------------------------------
 *  Used to compute the base to the power of exp(positive).
 */
int intPow(int base, int exp) {
	if (exp < 0) return -1;
	if (exp == 0) return 1;
	return intPow(base, exp - 1) * base;
}


