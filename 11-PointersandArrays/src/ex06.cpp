/*
 * File: ex06.cpp
 * -------------------
 *  This file reads in a gymnastics scores between 0 and 10
 *  from a set of judges and then computes  the average of 
 *  the scores after elimination both the highest and lowest scores
 *  from consideration.
 */

#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
#include "console.h"
#include "simpio.h"
#include "strlib.h"
using namespace std;

/* Constants */
const int MAX_JUDGES = 100;
const double MIN_SCORE = 0;
const double MAX_SCORE = 10;

/* Function prototypes */
void enterScores(double *pt, int *effsize);
double getAverageScore(double *pt, int nJudges, double *max, double *min);
bool isValidScore(double score);

int main() {
    double scores[MAX_JUDGES];
    int nJudges = 0;
    enterScores(scores, &nJudges);
    double max, min;
    double average = getAverageScore(scores, nJudges, &max, &min);
    cout << "The average after eliminating " << min << " and " << max <<
            " is " << fixed << average << endl;
    return 0;
}

void enterScores(double *ptScore, int *effsize) {
    cout << "Enter a score for each judge in the range 0 to 10." << endl;
    cout << "Enter a blank line to signal the end of the list." << endl;
    *effsize = 0;
    while (true) {
        if (*effsize >= MAX_JUDGES) break;
        string prompt = "Judge #" + integerToString(*effsize + 1) + ": ";
        string input = getLine(prompt);
        if (trim(input).empty()) break;
        double newscore = stringToReal(input);
        if (isValidScore(newscore)) {
            (*effsize)++;
            *ptScore++ = newscore;
        } else {
            cout << "Invalid input, please try again." << endl;
        }
    }
}

double getAverageScore(double *pt, int nJudges, double *max, double *min) {
    *max = MIN_SCORE - 1;
    *min = MAX_SCORE + 1;
    double sum = 0;
    for (int i = 0; i < nJudges; i++) {
        sum += *pt;
        if (*pt < *min) *min = *pt;
        if (*pt > *max) *max = *pt;
        pt++;
    }
    double average = 0;
    if (nJudges > 2) average = double(sum - *min - *max) / (nJudges - 2);
    return average;
    
}

bool isValidScore(double score) {
    return (score >= MIN_SCORE) && (score <= MAX_SCORE);
}
