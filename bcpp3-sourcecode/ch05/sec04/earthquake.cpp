#include <iostream>

using namespace std;

/**
   Gets the description of an earthquake for a given magnitude
   on the Richter scale.
   @param richter the magnitude on the Richter scale
   @return a description of the damage
*/
string get_description(double richter)
{
   if (richter >= 8.0)
   {
      return "Most structures fall";
   }
   if (richter >= 7.0)
   {
      return "Many buildings destroyed";
   }
   if (richter >= 6.0)
   {
      return "Many buildings considerably damaged, some collapse";
   }
   if (richter >= 4.5)
   {
      return "Damage to poorly constructed buildings";
   }
   return "No destruction of buildings";
}

int main()
{  
   cout << "Enter a magnitude on the Richter scale: ";
   double richter;
   cin >> richter;
   string description = get_description(richter);
   cout << description << endl;
   return 0;
}

