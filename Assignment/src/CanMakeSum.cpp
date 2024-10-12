/*
 * File: CanMakeSum.cpp
 * -----------------------------------
 *  H18.Assign3 - Subset Sum
 */

#include <iostream>
#include "vector.h"
#include "simpio.h"
#include "set.h"
using namespace std;

/* Function prototypes */

bool canMakeSum(Vector<int> & nums, int targetSum);  // in/out exhaustive recursion pattern
bool recCanMakeSum(Vector<int> & nums, int index, int targetSum, int & count);

bool canMakeSum2(Vector<int> & nums, int target);  // choose one from those remainning - recursive decomposition
bool recCanMakeSum2(Vector<int> & nums, int index, int sumSoFar, int target);

/* Main program */

int main() {
	Vector<int> nums;
	nums.add(3);
	nums.add(7);
	nums.add(1);
	nums.add(8);
	nums.add(-3);
	
	int target = getInteger("Enter target = ");

	
	int 

	cout << "{3, 7, 1, 8, -3} can make " 
		<< (canMakeSum(nums, target) ? "" : "not") 
		<< " sum " << target << ". " << endl;
/*
	// Another recursive decomposition
	cout << "{3, 7, 1, 8, -3} can make " 
		<< (canMakeSum2(nums, target) ? "" : "not") 
		<< " sum " << target << ". " << endl;
*/
	return 0;
}

/*
 * Function: canMakeSum
 * Usage: if(canMakeSum(nums, targetSum));
 * ---------------------------------------------------------------------------
 *  Warpper function - Given a set of integers and a target number, your goal is to find a subset
 *  of those numbers that sum to that target number.
 */
bool canMakeSum(Vector<int> & nums, int targetSum) {
	int count = 0;
	recCanMakeSum(nums, 0, targetSum, count);
	cout << "There are " << count << " such possible subset. " << endl;
	return (count > 0) ? true : false;

}

/*
 * Function: recCanMakeSum
 * Usage: if (recCamMakeSum(nums, 0, targetSum))
 * -------------------------------------------------------------------------
 *  Solve the subset problem in subset problem.
 */
bool recCanMakeSum(Vector<int> & nums, int index, int targetSum,  int & count) {
	// Simple case
	if (targetSum == 0) {
		count++;
		return true;
	}

	if (index >= nums.size()) return false;  //可以简化下（明确下）判断条件，在==下截止
	
	bool outF = recCanMakeSum(nums, index + 1, targetSum, count);
	bool inF = recCanMakeSum(nums, index + 1, targetSum - nums[index], count);
	
	if (inF) cout << nums[index] << endl;
	
	return inF || outF;
	// Recursive case
//	return  recCanMakeSum(nums, index + 1, targetSum) || 
//		recCanMakeSum(nums, index + 1, targetSum - nums[index]);  // return 两个函数的逻辑组合不需要加括号
}


bool canMakeSum2(Vector<int> & nums, int target) {
	return recCanMakeSum2(nums, 0, 0, target);
}

bool recCanMakeSum2(Vector<int> & nums, int index,  int sumSoFar, int target) {
	if (sumSoFar == target) return true;
	
	for (int i = index; i < nums.size(); i++) {
		if (recCanMakeSum2(nums, i + 1, sumSoFar + nums[i], target))  {
			cout << nums[i] << endl;
			return true;
		}
	}
	return false;
}

