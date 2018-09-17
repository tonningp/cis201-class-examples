/**
File: main.cpp
Description: This program uses factors to find a running list of prime numbers.  It will
only consider odd numbers past 2
Author: Paul Tonning
email: paul.tonning@student.vvc.edu
*/
#include <iostream>
using namespace std;

int main()
{
   unsigned consider;          // current consider for prime
   unsigned factor;         // possible factor of consider
   unsigned limit;          // find primes up to this value

   cout << "Find primes up to: ";
   cin >> limit;

   cout << "2" << endl << "3" << endl;    // treat first two primes as special case
   consider = 5;                            // initial consider
   while ( consider <= limit ) 
   {
    // look for a factor of consider 
      factor = 3;
      while ( factor*factor < consider && consider % factor != 0 )
         factor += 2;
      if ( consider % factor != 0 )
         cout << consider << endl;
      consider += 2;    // only look at odd numbers
   }
   return 0;
}
