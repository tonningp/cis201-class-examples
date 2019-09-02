#include <iostream>

using namespace std;

/**
   Computes a Fibonacci number.
   @param n an integer
   @return the nth Fibonacci number
*/
int fib(int n)
{  
   cout << "Entering fib: n = " << n << endl;
   int f;
   if (n <= 2) { f = 1; }
   else { f = fib(n - 1) + fib(n - 2); }
   cout << "Exiting fib: n = " << n
      << " return value = " << f << endl;
   return f;
}

int main()
{  
   cout << "Enter n: ";
   int n;
   cin >> n;
   int f = fib(n);
   cout << "fib(" << n << ") = " << f << endl;
   return 0;
}
