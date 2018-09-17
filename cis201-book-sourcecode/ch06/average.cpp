#include <iostream>
#include <vector>

using namespace std;

/** 
   Computes the average of a vector of floating-point values.
   @param values a vector of floating-point values
   @return the average of the values
*/
double average(vector<double> values)
{  
   if (values.size() == 0) return 0;
   double sum = 0;
   for (int i = 0; i < values.size(); i++)
      sum = sum + values[i];
   return sum / values.size();
}

int main()
{  
   vector<double> salaries(5);
   salaries[0] = 35000.0;
   salaries[1] = 63000.0;
   salaries[2] = 48000.0;
   salaries[3] = 78000.0;
   salaries[4] = 51500.0;

   double avgsal = average(salaries);
   cout << "The average salary is " << avgsal << "\n";
   return 0;
}
