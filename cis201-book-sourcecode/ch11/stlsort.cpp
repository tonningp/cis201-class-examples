#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#include "ccc_empl.h"

bool operator<(const Employee& a, const Employee& b)
{
   return a.get_salary() < b.get_salary();
}

int main()
{  
   vector<Employee> staff(5);
   staff[0] = Employee("Cracker, Carl", 48000.0);
   staff[1] = Employee("Hacker, Harry", 35000.0);
   staff[2] = Employee("Lam, Larry", 78000.0);
   staff[3] = Employee("Reindeer, Rudolf", 63000.0);
   staff[4] = Employee("Sandman, Susan", 51500.0);

   sort(staff.begin(), staff.end());

   for (int i = 0; i < staff.size(); i++)
      cout << staff[i].get_name() << " " << staff[i].get_salary() << "\n";

   return 0;
}

