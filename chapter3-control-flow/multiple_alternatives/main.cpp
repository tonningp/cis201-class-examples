#include<iostream>   

using namespace std;

int main()
{
   double richter=7.0;
   if (richter >= 8.0)
      cout << "Most structures fall";
   else if (richter >= 7.0)
      cout << "Many buildings destroyed";
   else if (richter >= 6.0)
      cout << "Many buildings considerably damaged, some collapse";
   else if (richter >= 4.5)
      cout << "Damage to poorly constructed buildings";
   else
      cout << "Generally no damage";
   return 0;
}
