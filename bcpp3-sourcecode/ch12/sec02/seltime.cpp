#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

/** 
    Gets the position of the smallest element in an array range.
    @param a the array
    @param from the beginning of the range
    @param to the end of the range
    @return the position of the smallest element in 
    the range a[from]...a[to]
*/
int min_position(int a[], int from, int to)
{  
   int min_pos = from;
   for (int i = from + 1; i <= to; i++)
   {
      if (a[i] < a[min_pos]) { min_pos = i };
   }
   return min_pos;
}

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
   Sorts a array using the selection sort algorithm.
   @param a the array to sort
   @param size the number of elements in a
*/
void selection_sort(int a[], int size)
{  
   for (int next = 0; next < size - 1; next++)
   {  
      // Find the position of the minimum
      int min_pos = min_position(a, next, size - 1);
      // Swap the next element and the minimum
      swap(a[next], a[min_pos]);
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

const int MAX_SIZE = 10000000;
int values[MAX_SIZE];

int main()
{  
   srand(time(0));
   cout << "Enter array size: ";
   int size;
   cin >> size;
   for (int i = 0; i < size; i++)
   {
      values[i] = rand() % 100;
   }
   int before = time(0);
   selection_sort(values, size);
   int after = time(0);
   cout << "Elapsed time: " << after - before
      << " seconds" << endl;
   return 0;
}
