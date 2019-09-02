/*
   This program demonstrates comparisons of numbers, using 
   Boolean expressions.
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
   cout << "Enter two numbers (such as 3.5 4.5): ";
   double x;
   cin >> x;
   double y;
   cin >> y;
   if (x == y) 
   {
      cout << "They are the same.";
   }
   else 
   {
      cout << "The first number is ";
      if (x > y)
      {
         cout << "larger" << endl;
      }
      else
      {
         cout << "smaller" << endl;
      }

      if (-0.01 < x - y && x - y < 0.01)
      {
         cout << "The numbers are close together" << endl;
      }

      if (x == y + 1 || x == y - 1)
      {
         cout << "The numbers are one apart" << endl;
      }

      if (x > 0 && y > 0 || x < 0 && y < 0)
      {
         cout << "The numbers have the same sign" << endl;
      }
      else
      {
         cout << "The numbers have different signs" << endl;
      }
   }
   return 0;
}
