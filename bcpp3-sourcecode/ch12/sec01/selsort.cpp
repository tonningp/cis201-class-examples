#include <cstdlib>
#include <ctime>
#include <iostream>

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
      if (a[i] < a[min_pos]) { min_pos = i; }
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
   Sorts a array using the selection sort algorithm
   @param a the array to sort
   @param size the number of elements in a
*/
void selection_sort(int a[], int size)
{  
   int next; // The next position to be set to the minimum

   for (next = 0; next < size - 1; next++)
   {  
      // Find the position of the minimum starting at next
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
   selection_sort(values, SIZE);
   print(values, SIZE);
   return 0;
}
