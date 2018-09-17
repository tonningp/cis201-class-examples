#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>

using namespace std;

int main()
{  
   // Sets the seed of the random number generator.
   srand(time(0));

   const int NTRIES = 10000;
   const double PI = 3.141592653589793;

   int hits = 0;
   for (int i = 1; i <= NTRIES; i++)
   {  
      double ylow = 2 * (rand() * 1.0 / RAND_MAX);
      double angle = 180 * (rand() * 1.0 / RAND_MAX);
      double yhigh = ylow + sin(angle * PI / 180);
      if (yhigh >= 2) hits++;                      
   }
   cout << "Tries / Hits = " 
      << NTRIES * (1.0 / hits) << "\n";
   return 0;
}
