#include <iostream>

#include "util.h"

/** 
    Gets the position of the smallest element in a vector range.
    @param a the vector
    @param from the beginning of the range
    @param to the end of the range
    @return the position of the smallest element in 
    the range a[from]...a[to]
*/
int min_position(vector<int>& a, int from, int to)
{  
   int min_pos = from;
   int i;
   for (i = from + 1; i <= to; i++)
      if (a[i] < a[min_pos]) min_pos = i;
   return min_pos;
}

/** 
   Sorts a vector using the selection sort algorithm
   @param a the vector to sort
*/
void selection_sort(vector<int>& a)
{  
   int next; // The next position to be set to the minimum

   for (next = 0; next < a.size() - 1; next++)
   {  
      // Find the position of the minimum
      int min_pos = min_position(a, next, a.size() - 1);
      if (min_pos != next)
         swap(a[min_pos], a[next]);
   }
}

int main()
{  
   rand_seed();
   vector<int> v(20);
   for (int i = 0; i < v.size(); i++)
      v[i] = rand_int(1, 100);
   print(v);
   selection_sort(v);
   print(v);
   return 0;
}
