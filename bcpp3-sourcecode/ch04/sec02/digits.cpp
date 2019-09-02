#include <iostream>

using namespace std;

int main()
{
   cout << "Enter an integer: ";
   int n;
   cin >> n;

   int sum = 0;
   while (n > 0)
   {
      int digit = n % 10;
      sum = sum + digit;
      n = n / 10;
   }
   cout << sum << endl;
   
   return 0;
}
