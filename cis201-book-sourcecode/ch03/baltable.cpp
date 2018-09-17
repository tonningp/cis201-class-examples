#include <iostream>
#include <iomanip>

using namespace std;

int main()
{  
   double rate = 5;
   double balance = 10000;
   
   for (int year = 0; year <= 10; year++)
   {  
      cout << setw(2) << year << ": " 
         << fixed << setprecision(2) << balance << "\n";  
      double interest = balance * rate / 100;
      balance = balance + interest;
   }
   return 0;
}
