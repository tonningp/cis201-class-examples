#include <iostream>
#include "fraction.h"

using namespace std;

int main()
{
   Fraction f(1, 2);
   Fraction g(1, 3);
   cout << "f + g: " << f + g << endl;
   cout << "f * g: " << f * g << endl;
   cout << "f / g: " << f / g << endl;
   cout << "Enter a fraction: ";
   Fraction h;
   cin >> h;
   if (f == h)
   {
      cout << "Your input equals 1/2" << endl;
   }
   else
   {
      cout << "f - h: " << f - h << endl;
   }
   return 0;
}
