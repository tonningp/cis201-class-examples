#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
   Removes an element from an unordered vector.
   @param values a vector
   @param pos the position of the element to erase
*/
void erase(vector<string>& values, int pos)
{  
   int last_pos = values.size() - 1;
   values[pos] = values[last_pos];
   values.pop_back();
}

/** 
   Prints all elements in a vector.
   @param values the vector to print
*/
void print(vector<string> values)
{  
   for (int i = 0; i < values.size(); i++)
      cout << "[" << i << "] " << values[i] << "\n";
}

int main()
{  
   vector<string> staff(5);
   staff[0] = "Hacker, Harry";
   staff[1] = "Reindeer, Rudolf";
   staff[2] = "Cracker, Carl";
   staff[3] = "Lam, Larry";
   staff[4] = "Sandman, Susan";
   print(staff);

   int pos;
   cout << "Remove which element? ";
   cin >> pos;

   erase(staff, pos);
   print(staff);
   return 0;
}
