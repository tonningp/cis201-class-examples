#include <iostream>
#include "pair.h"

using namespace std;

Pair<int> minmax(int data[], int size)
{
   int min = data[0];
   int max = data[0];
   for (int i = 1; i < size; i++)
   {
      if (data[i] < min) { min = data[i]; }
      if (data[i] > max) { max = data[i]; }
   }
   return Pair<int>(min, max);
}

int main()
{
   int values[] = { 3, 1, 4, 1, 5, 9, 2, 6 };
   Pair<int> result = minmax(values, 8);
   cout << "Minimum: " << result.get_first() << endl;
   cout << "Maximum: " << result.get_second() << endl;
   return 0;
}
