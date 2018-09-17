#ifndef UTIL_H
#define UTIL_H

#include <vector>

using namespace std;

/**
   Swaps two integers.
   @param x the first integer to swap
   @param y the second integer to swap
*/
void swap(int& x, int& y);

/** 
   Prints all elements in a vector
   @param a the vector to print
*/
void print(vector<int> a);

/**
   Sets the seed of the random number generator.
*/
void rand_seed();

/** 
   Computes a random integer in a range.
   @param a the bottom of the range
   @param b the top of the range
   @return a random integer x, a <= x and x <= b
*/
int rand_int(int a, int b);

#endif 
