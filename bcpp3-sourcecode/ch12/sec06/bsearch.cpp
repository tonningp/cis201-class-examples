#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

/**
   Finds an element in a sorted array.
   @param a the sorted array with the elements to search
   @param from the start of the range to search
   @param to the end of the range to search
   @param value the value to search for
   @return the index of the first match, or -1 if not found
*/
int binary_search(int a[], int from, int to, int value)
{  
   if (from > to) 
   { 
      return -1; 
   }

   int mid = (from + to) / 2;
   if (a[mid] == value)
   {
      return mid;
   }
   else if (a[mid] < value)
   {
      return binary_search(a, mid + 1, to, value);
   }
   else
   {
      return binary_search(a, from, mid - 1, value);
   }
}

int main()
{  
   srand(time(0));
   const int SIZE = 20;
   int values[SIZE];
   values[0] = 0;
   for (int i = 1; i < SIZE; i++)
   {
      values[i] = values[i - 1] + rand() % 10;
      cout << values[i] << " ";
   }
   cout << endl;

   cout << "Enter number to search for: ";
   int target;
   cin >> target;
   int pos = binary_search(values, 0, SIZE - 1, target);
   cout << "Found in position " << pos << endl;
   return 0;
}

