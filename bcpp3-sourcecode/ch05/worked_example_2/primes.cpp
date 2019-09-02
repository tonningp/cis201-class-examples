#include <iostream>

using namespace std;

// Caution: This program has bugs.

/**
   Tests if an integer is a prime.
   @param n any positive integer
   @return true if n is a prime, false otherwise
*/
bool isprime(int n)
{
   if (n == 2)
   {
      // 2 is a prime
      return true;
   }
   if (n % 2 == 0)
   {
      // No other even number is a prime
      return false;
   }

   // Try finding a number that divides n

   int k = 3; // No need to divide by 2 since n is odd
   // Only need to try divisors up to sqrt(n)
   while (k * k < n)
   {
      if (n % k == 0)
      {
         // n is not a prime since it is divisible by k
         return false;
      }
      // Try next odd number
      k = k + 2;
   }

   // No divisor found. Therefore, n is a prime
   return true;
}

int main()
{
   cout << "Please enter the upper limit: ";
   int n;
   cin >> n;
   for (int i = 1; i <= n; i = i + 2)
   {
      if (isprime(i))
      {
         cout << i << endl;
      }
    }
    return 0;
}
