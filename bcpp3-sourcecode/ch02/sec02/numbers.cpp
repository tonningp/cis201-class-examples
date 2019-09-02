#include <iostream>
#include <cmath>

using namespace std;

int main()
{
   int pennies = 1729;   
   int dollars = pennies / 100; // The remainder is discarded
   int cents = pennies % 100; // The % operator yields the remainder
   cout << "Dollars: " << dollars << endl;
   cout << "Cents: " << cents << endl;

   double price = 2.55;
   dollars = price; // Assigning to an int drops the fractional part
   cout << "Integer part of " << price << ": " << dollars << endl;
   dollars = price + 0.5; // Rounds to nearest integer
   cout << "Nearest integer to " << price << ": " << dollars << endl;

   // The decimal logarithm of a number can be used
   // to determine the number of digits.
   double population = 73693997551.0; 
   double decimal_log = log10(population);
   int digits = decimal_log; // Drop fractional part
   cout << "Decimal log of " << population << ": "
      << decimal_log << endl;
   cout << "Digits: " << digits << endl;
   
   return 0;
}
