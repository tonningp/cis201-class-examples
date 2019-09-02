#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

/**
   Sorts an array, using insertion sort.
   @param a the array to sort
*/
void insertion_sort(int a[], int size)
{
   for (int i = 1; i < size; i++)
   {
      int next = a[i];
      // Move all larger elements up
      int j = i;
      while (j > 0 && a[j - 1] > next)
      {
         a[j] = a[j - 1];
         j--;
      }
      // Insert the element
      a[j] = next;
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
   insertion_sort(values, SIZE);
   print(values, SIZE);
   return 0;
}

