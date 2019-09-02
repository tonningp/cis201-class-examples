#include <iostream>

using namespace std;

/**
   In this program, we use reinterpret_cast<long>(p) to turn a pointer
   p into a long integer for display of the pointer value. In Figures
   3 and 4 of the book, the address was arbitrarily assumed to be 
   at 20300. When you run the program, the value will be different. 
   However, what matters is whether two pointer values are identical, 
   or by which amount they differ.
*/

double sum(double values[], int size)
{
   cout << "Value of values: " << reinterpret_cast<long>(values) << endl;
   double total = 0;
   for (int i = 0; i < size; i++)
   {
      total = total + values[i];
   }
   return total;
}

int main()
{
   double a[10];
   for (int i = 0; i < 10; i++) { a[i] = i * i; }

   double* p = a; // Points to a[0]
   cout << "Initial element: " << *p << endl;
   cout << "Three elements further: " << *(p + 3) << endl;

   cout << "Value of p: " << reinterpret_cast<long>(p) << endl;
   cout << "Value of p + 3: " << reinterpret_cast<long>(p + 3) << endl;
   cout << "Note that p + 3 is 24 bytes further than p." << endl;

   double s = sum(a, 10);
   cout << "Note that the address of a was passed to sum." << endl;
   cout << "Sum: " << s << endl;
   return 0;
}
