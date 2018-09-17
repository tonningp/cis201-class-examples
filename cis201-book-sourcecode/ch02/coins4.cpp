#include <iostream>

using namespace std;

int main()
{  
   cout << "How many pennies do you have? ";
   int pennies;
   cin >> pennies;
   
   cout << "How many nickels do you have? ";
   int nickels;
   cin >> nickels;

   cout << "How many dimes do you have? ";
   int dimes;
   cin >> dimes;

   cout << "How many quarters do you have? ";
   int quarters;
   cin >> quarters;

   const int PENNIES_PER_NICKEL = 5;
   const int PENNIES_PER_DIME = 10;
   const int PENNIES_PER_QUARTER = 25;
   const int PENNIES_PER_DOLLAR = 100;

   int value = pennies + PENNIES_PER_NICKEL * nickels 
      + PENNIES_PER_DIME * dimes + PENNIES_PER_QUARTER * quarters;
   int dollar = value / PENNIES_PER_DOLLAR;
   int cents = value % PENNIES_PER_DOLLAR;

   cout << "Total value = " << dollar << " dollars and "
      << cents << " cents.\n";

   return 0;
}

