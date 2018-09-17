#include <iostream>

using namespace std;

/**
   Reads data into an array, using 0 as a sentinel value.
   @param a the array to fill
   @param a_capacity the maximum size of a
   @param a_size filled with the size of a after reading the input
*/
void read_data(double a[], int a_capacity, int& a_size)
{
   a_size = 0;

   bool more = true;
   while (more)
   {
      double x;
      cin >> x;
      if (x == 0)
         more = false;
      else if (a_size == a_capacity)
      {
         cout << "Sorry--extra data ignored\n";
         more = false;
      }
      else
      {
         a[a_size] = x;
         a_size++;
      }
   }
}

/**
   Computes the maximum value in an array.
   @param a the array
   @param a_size the number of values in a
*/
double maximum(const double a[], int a_size)
{
   if (a_size == 0)
      return 0;
   double highest = a[0];
   for (int i = 1; i < a_size; i++)
      if (a[i] > highest)
         highest = a[i];
   return highest;
}

int main()
{
   const int SALARIES_CAPACITY = 100;
   double salaries[SALARIES_CAPACITY];
   int salaries_size = 0;
   cout << "Please enter salaries, 0 to quit:\n";

   read_data(salaries, SALARIES_CAPACITY, salaries_size);

   double maxsal = maximum(salaries, salaries_size);
   cout << "The maximum salary is " << maxsal << "\n";
   return 0;
}
