#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
   const int FIRST_CLASS_STAMP_PRICE = 47; // Price in pennies

   cout << "Enter number of dollars: ";
   int dollars; 
   cin >> dollars;

   int first_class_stamps = 100 * dollars / FIRST_CLASS_STAMP_PRICE;
   int penny_stamps = 100 * dollars - first_class_stamps 
      * FIRST_CLASS_STAMP_PRICE;
   cout << "First class stamps: " << setw(6) << first_class_stamps << endl
        << "Penny stamps:       " << setw(6) << penny_stamps << endl;

   return 0;
}
