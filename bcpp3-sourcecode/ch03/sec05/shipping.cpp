#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
   cout << "Enter the state or province: ";
   string state;
   cin >> state;

   cout << "Enter the country: ";
   string country;
   cin >> country;

   double shipping_cost;

   if (country == "USA")
   {
      if (state == "AK" || state == "HI")
         // See Section 3.7 for the || (or) operator
      {
         shipping_cost = 10;
      }
      else
      {
         shipping_cost = 5;
      }
   }
   else
   {
      shipping_cost = 10;
   }

   cout << "Shipping cost to " << state << ", " << country << ": "
      << fixed << setprecision(2) << shipping_cost << endl;
   return 0;
}
