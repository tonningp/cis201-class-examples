#include <iostream>

#include "util.h"

/**
   Finds an element in a vector
   @param v the vector with the elements to search
   @param value the value to search for
   @return the index of the first match, or -1 if not found
*/
int linear_search(vector<int> v, int value)
{  
   for (int i = 0; i < v.size(); i++)
   {  
      if (v[i] == value)
         return i;
   }
   return -1;
}


int main()
{  
   rand_seed();
   vector<int> v(20);
   for (int i = 0; i < v.size(); i++)
      v[i] = rand_int(1, 100);
   print(v);
   cout << "Enter number to search for: ";
   int n;
   cin >> n;
   int j = linear_search(v, n);
   cout << "Found in position " << j << "\n";
   return 0;
}
