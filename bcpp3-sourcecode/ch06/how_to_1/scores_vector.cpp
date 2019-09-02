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
   bool done = false;
   while (!done)
   {  
      double input;
      cin >> input;
      if (cin.fail())
      {
         done = true;
      }
      else 
      {
         result.push_back(input);
      }
   }
   return result;
}

/**
   Gets the minimum value from a vector.
   @param values a vector of size >= 1
   @return the smallest element of values
*/
double minimum(vector<double> values)
{
   double smallest = values[0];
   for (int i = 1; i < values.size(); i++)
   {
      if (values[i] < smallest)
      {
         smallest = values[i];
      }
   }
   return smallest;
}

/**
   Computes the sum of the values in a vector.
   @param values a vector
   @return the sum of the values in values
*/
double sum(vector<double> values)
{
   double total = 0;
   for (int i = 0; i < values.size(); i++)
   {
      total = total + values[i];
   }
   return total;
}

int main()
{
   vector<double> scores = read_inputs();
   if (scores.size() == 0)
   {
      cout << "At least one score is required." << endl;
   }
   else
   {
      double final_score = sum(scores) - minimum(scores); 
      cout << "Final score: " << final_score << endl;
   }
   return 0;
}
