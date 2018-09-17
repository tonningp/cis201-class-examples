#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
   Inserts an element into a vector.
   @param values a vector
   @param pos the position before which to insert the element
   @param s the element to insert
*/
void insert(vector<string>& values, int pos, string s)
{  
   int last = values.size() - 1; 
   values.push_back(values[last]);
   for (int i = last; i > pos; i--)
      values[i] = values[i - 1];
   values[pos] = s;
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
   staff[0] = "Cracker, Carl";
   staff[1] = "Hacker, Harry";
   staff[2] = "Lam, Larry";
   staff[3] = "Reindeer, Rudolf";
   staff[4] = "Sandman, Susan";
   print(staff);

   int pos;
   cout << "Insert before which element? ";
   cin >> pos;

   insert(staff, pos, "New, Nina");
   print(staff);
   return 0;
}
