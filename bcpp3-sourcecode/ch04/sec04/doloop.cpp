#include <iostream>
#include <string>
#include <cmath>

using namespace std;

/**
   This program shows how you can prompt for input that fulfills
   a certain condition. Try entering negative values, such as
   -2 or -0.5, to see how they are rejected.
*/
int main()
{
   double value;
   do
   {
      cout << "Enter a number >= 0: ";
      cin >> value;
   }
   while (value < 0);
   double root = sqrt(value);
   cout << "The square root of the number is " << root << endl;   
}
