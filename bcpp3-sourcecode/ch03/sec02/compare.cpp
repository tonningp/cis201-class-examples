#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
   // Integers

   int m = 2;
   int n = 4;

   if (m * m == n)
   {
      cout << "2 times 2 is 4" << endl;
   }

   // Floating-point numbers

   double x = sqrt(2);
   double y = 2.0;

   if (x * x == y)
   {
      cout << "sqrt(2) times sqrt(2) is 2" << endl;
   }
   else
   {
      cout << "sqrt(2) times sqrt(2) is not 2 but "
         << fixed << setprecision(18) << x * x << endl;
   }

   const double EPSILON = 1E-14;
   if (abs(x * x - y) < EPSILON)
   {
      cout << "sqrt(2) times sqrt(2) is approximately 2" << endl;
   }

   // Strings

   string s = "120";
   string t = "20";

   if (s < t)
   {
      cout << s << " comes before " << t << endl;
   }
   else if (s > t)
   {
      cout << s << " comes after " << t << endl;
   }
   else
   {
      cout << s << " is the same as " << t << endl;
   }
   
   return 0;
}

