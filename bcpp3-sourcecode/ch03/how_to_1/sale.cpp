#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
   cout << "Original price before discount: ";
   double original_price;
   cin >> original_price;

   double discount_rate;
   if (original_price < 128)
   {
      discount_rate = 0.92;
   }
   else
   {
      discount_rate = 0.84;
   }
   double discounted_price = discount_rate * original_price;

   cout << "Discounted price: " << fixed << setprecision(2)
      << discounted_price << endl;
   return 0;
}
