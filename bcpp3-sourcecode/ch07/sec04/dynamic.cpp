#include <iostream>

using namespace std;

int main()
{
   double* account_pointer = new double;
   *account_pointer = 1000;
   cout << "Allocated one new variable containing " << *account_pointer
      << endl;
   cout << endl;

   int n = 10;
   double* account_array = new double[n];
   for (int i = 0; i < n; i++)
   {
      account_array[i] = 1000 * i;
   }   
   cout << "Allocated an array of size " << n << endl;
   for (int i = 0; i < n; i++)
   {
      cout << i << ": " << account_array[i] << endl;
   }
   cout << endl;

   // Doubling the array capacity 
   double* bigger_array = new double[2 * n];
   for (int i = 0; i < n; i++)
   {
      bigger_array[i] = account_array[i];
   }
   delete[] account_array; // Deleting smaller array
   account_array = bigger_array;
   n = 2 * n;

   cout << "Now there is room for an additional element:" << endl;
   account_array[10] = 10000;
   cout << 10 << ": " << account_array[10] << endl;    
   
   delete account_pointer;
   delete[] account_array; // Deleting larger array
   
   return 0;
}
