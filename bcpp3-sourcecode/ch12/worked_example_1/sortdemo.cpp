#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>

#include "shellsort.h"

using namespace std;

/**
   Fills an array with random integers between 0 and 99.
   @param a the array to print
   @param size the number of elements in a
*/
void random_fill(int a[], int size)
{
   for (int i = 0; i < size; i++)
   {
      a[i] = rand() % 100;
   }
}

/** 
   Prints all elements in an array.
   @param a the array to print
   @param size the number of elements in a
*/
void print(int a[], int size)
{  
   for (int i = 0; i < size; i++)
   {
      cout << a[i] << " ";
   }
   cout << endl;
}

const int MAX_SIZE = 50000000;
int values[MAX_SIZE];

int main()
{  
   srand(time(0));
   int size = 20;

   cout << "Demo with " << size << " elements:" << endl;
   random_fill(values, size);
   print(values, size);
   shell_sort(values, size);
   print(values, size);
   cout << "Enter array size: ";
   cin >> size;
   const int ITERATIONS = 1000;

   int before = time(0);
   srand(before);
   for (int i = 1; i <= ITERATIONS; i++)
   {
      random_fill(values, size);
      shell_sort(values, size);
   }
   int after = time(0);
   cout << "Elapsed time with Shell sort: "
      << (after - before) * 1.0 / ITERATIONS << " seconds" << endl;

   srand(before); // Make sure we get the same arrays again
   before = time(0);
   for (int i = 1; i <= ITERATIONS; i++)
   {
      random_fill(values, size);
      sort(values, values + size);
   }
   after = time(0);
   cout << "Elapsed time with the library sort: " 
      << (after - before) * 1.0 / ITERATIONS << " seconds" << endl;

   random_fill(values, size);
   before = time(0);
   insertion_sort(values, size, 0, 1);
   after = time(0);
   cout << "Elapsed time with insertion sort: " << after - before
      << " seconds" << endl;
   
   return 0;
}
