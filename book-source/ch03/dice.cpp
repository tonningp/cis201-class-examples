#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{  
   // Sets the seed of the random number generator.
   srand(time(0));

   for (int i = 1; i <= 10; i++)
   {  
      int d1 = 1 + rand() % 6;
      int d2 = 1 + rand() % 6;
      cout << d1 << " " << d2 << "\n";
   }
   cout << "\n";
   return 0;
}
