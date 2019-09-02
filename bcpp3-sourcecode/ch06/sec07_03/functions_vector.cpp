#include <iostream>
#include <vector>

using namespace std;

/**
   Reads a sequence of floating-point numbers.
   @return a vector containing the numbers
*/
vector<double> read_inputs()
{
   vector<double> result;
   cout << "Please enter values, Q to quit:" << endl;
   bool more = true;
   while (more)
   {  
      double input;
      cin >> input;
      if (cin.fail())
      {
         more = false;
      }
      else 
      {
         result.push_back(input);
      }
   }
   return result;
}

/**
   Multiplies all elements of a vector by a factor
   @param values a vector
   @param factor the value with which each element is multiplied
*/
void multiply(vector<double>& values, double factor)
{
   for (int i = 0; i < values.size(); i++)
   {
      values[i] = values[i] * factor;
   }
}

/**
   Prints the elements of a vector, separated by commas.
   @param values a vector
*/
void print(vector<double> values)
{
   for (int i = 0; i < values.size(); i++)
   {
      if (i > 0) { cout << ", "; }
      cout << values[i];
   }
   cout << endl;
}

int main()
{  
   vector<double> values = read_inputs();
   multiply(values, 2);
   print(values);

   return 0;
}
