#include <iostream>
#include <iomanip>

using namespace std;

int main()
{  
   double rate = 5;
   double balance = 10000;
   
   for (int year = 1; year <= 10; year++)
   {  
      double interest = balance * rate / 100;
      balance = balance + interest;
      cout << setw(2) << year << ": " 
         << fixed << setprecision(2) << balance << "\n";  
   }
   return 0;
}
