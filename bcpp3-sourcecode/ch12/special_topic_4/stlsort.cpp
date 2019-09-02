#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#include "employee.h"

/** 
   Prints all elements in an array.
   @param a the array to print
   @param size the number of elements in a
*/
void print(int a[], int size)
{  
   for (int i = 0; i < size; i++)
   {
      cout << a[i] << " ";
   }
   cout << endl;
}

bool operator<(const Employee& a, const Employee& b)
{
   return a.get_salary() < b.get_salary();
}

int main()
{  
   const int SIZE = 5;
   int values[SIZE] = { 48, 35, 78, 63, 51 };

   sort(values, values + SIZE);

   print(values, SIZE);

   vector<Employee> staff(SIZE);
   staff[0] = Employee("Cracker, Carl", 48000.0);
   staff[1] = Employee("Hacker, Harry", 35000.0);
   staff[2] = Employee("Lam, Larry", 78000.0);
   staff[3] = Employee("Reindeer, Rudolf", 63000.0);
   staff[4] = Employee("Sandman, Susan", 51000.0);

   sort(staff.begin(), staff.end());

   for (int i = 0; i < staff.size(); i++)
   {
      cout << staff[i].get_name() << " " << staff[i].get_salary() << endl;
   }

   return 0;
}

