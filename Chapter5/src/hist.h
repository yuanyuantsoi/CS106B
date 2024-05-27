/*
 * File: hist.h
 * ----------------------------------------
 *  The interface gives clients more control
 *  over the format of the histogram.
 */


#ifndef _hist_h
#define _hist_h

#include <string>
#include <cctype>
#include "simpio.h"

void setHisogramNum(int count); // sets the nubmer of bars in Histogram
void setBoundInEachBar(int min, int max); 
