#include <iostream>
#include <vector>

using namespace std;

/**
   Returns all values within a range.
   @param values a vector of floating-point numbers
   @param low the low end of the range
   @param high the high end of the range
   @return a vector of the given values that fall within the range
*/
vector<double> between(vector<double> values,
    double low, double high)
{  
   vector<double> result;
   for (int i = 0; i < values.size(); i++)
      if (low <= values[i] && values[i] <= high)
         result.push_back(values[i]);
   return result;
}

int main()
{  
   vector<double> salaries(5);
   salaries[0] = 35000.0;
   salaries[1] = 63000.0;
   salaries[2] = 48000.0;
   salaries[3] = 78000.0;
   salaries[4] = 51500.0;

   vector<double> midrange_salaries
      = between(salaries, 45000.0, 65000.0);

   for (int i = 0; i < midrange_salaries.size(); i++)
      cout << midrange_salaries[i] << "\n";

   return 0;
}

