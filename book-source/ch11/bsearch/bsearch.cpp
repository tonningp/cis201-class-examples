#include <iostream>

#include "util.h"

/**
   Finds an element in a sorted vector.
   @param v the sorted vector with the elements to search
   @param from the start of the range to search
   @param to the end of the range to search
   @param value the value to search for
   @return the index of the first match, or -1 if not found
*/
int binary_search(vector<int> v, int from, int to, int value)
{  
   if (from > to)
      return -1;
   int mid = (from + to) / 2;
   if (v[mid] == value)
      return mid;
   else if (v[mid] < value)
      return binary_search(v, mid + 1, to, value);
   else
      return binary_search(v, from, mid - 1, value);
}

int main()
{  
   rand_seed();
   vector<int> v(20);
   v[0] = 1;
   for (int i = 1; i < v.size(); i++)
      v[i] = v[i - 1] + rand_int(1, 10);

   print(v);
   cout << "Enter number to search for: ";
   int n;
   cin >> n;
   int j = binary_search(v, 0, v.size() - 1, n);
   cout << "Found in position " << j << "\n";
   return 0;
}
