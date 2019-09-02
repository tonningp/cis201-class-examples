#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

/**
   Finds an element in an array.
   @param a the array with the elements to search
   @param size the number of elements in a
   @param value the value to search for
   @return the index of the first match, or -1 if not found
*/
int linear_search(int a[], int size, int value)
{  
   for (int i = 0; i < size; i++)
   {  
      if (a[i] == value)
      {
         return i;
      }
   }
   return -1;
}

int main()
{  
   srand(time(0));
   const int SIZE = 20;
   int values[SIZE];
   for (int i = 0; i < SIZE; i++)
   {
      values[i] = rand() % 100;
      cout << values[i] << " ";
   }
   cout << endl;

   cout << "Enter number to search for: ";
   int target;
   cin >> target;
   int pos = linear_search(values, SIZE, target);
   cout << "Found in position " << pos << endl;
   return 0;
}
