#include <iostream>

using namespace std;

int main()
{  
   cout << "Enter a magnitude on the Richter scale: ";
   double richter;
   cin >> richter;

   if (richter >= 8.0)
   {
      cout << "Most structures fall";
   }
   else if (richter >= 7.0)
   {
      cout << "Many buildings destroyed";
   }
   else if (richter >= 6.0)
   {
      cout << "Many buildings considerably damaged, some collapse";
   }
   else if (richter >= 4.5)
   {
      cout << "Damage to poorly constructed buildings";
   }
   else 
   {
      cout << "No destruction of buildings";
   }
   cout << endl;
   return 0;
}

