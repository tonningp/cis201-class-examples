#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

/**
   Swaps two integers.
   @param x the first integer to swap
   @param y the second integer to swap
*/
void swap(int& x, int& y)
{  
   int temp = x;
   x = y;
   y = temp;
}

/**
   Partitions a portion of an array.
   @param a the array to partition
   @param from the first index of the portion to be partitioned
   @param to the last index of the portion to be partitioned
   @return the last index of the first partition
*/
int partition(int a[], int from, int to)
{
   int pivot = a[from];
   int i = from - 1;
   int j = to + 1;
   while (i < j)
   {
      i++; while (a[i] < pivot) { i++; }
      j--; while (a[j] > pivot) { j--; }
      if (i < j) { swap(a[i], a[j]); }
   }
   return j;
}

/**
   Sorts a portion of an array, using quick sort.
   @param a the array to sort
   @param from the first index of the portion to be sorted
   @param to the last index of the portion to be sorted
*/
void quicksort(int a[], int from, int to)
{
   if (from >= to) { return; }
   int p = partition(a, from, to);
   quicksort(a, from, p);
   quicksort(a, p + 1, to);
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

int main()
{  
   srand(time(0));
   const int SIZE = 20;
   int values[SIZE];
   for (int i = 0; i < SIZE; i++)
   {
      values[i] = rand() % 100;
   }
   print(values, SIZE);
   quicksort(values, 0, SIZE - 1);
   print(values, SIZE);
   return 0;
}

