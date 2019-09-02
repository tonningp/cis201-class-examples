#include <iostream>
#include <cmath>

using namespace std;

/**
   This program combines several common loop algorithms. 
*/
int main()
{
   cout << "Enter input: ";
   int input;
   cin >> input;
   int min = input; // Set the smallest to the first input
   int max = input; // Set the largest to the first input

   int count = 1; // The number of inputs
   int sum = input; // Add the first input to the sum of the inputs

   bool found_negative = false; // Set to true if we found at least one negative input
   int negatives; // The count of negative inputs
   int first_negative = 0; // The position of the first negative input

   if (input < 0)
   {
      found_negative = true;
      first_negative = 1;
      negatives = 1;
   }
   else
   {
      negatives = 0;
   }
   
   bool done = false;
   while (!done)
   {
      cout << "Enter input, 0 to quit: ";
      cin >> input;
      if (input == 0) // Zero is the sentinel value
      {
         done = true;
      }
      else 
      {
         sum = sum + input; // Computing sum and average
         count++;
         
         if (input < min) // Determining minimum and maximum
         {
            min = input;
         }
         else if (input > max)
         {
            max = input;
         }
         
         if (input < 0) // Counting matches
         {
            negatives++;
            
            if (!found_negative) // Finding first match
            {
               found_negative = true;
               first_negative = count;
            }
         }
      }
   }   
   cout << "Minimum: " << min << endl;
   cout << "Maximum: " << max << endl;
   cout << "Sum: " << sum << endl;
   cout << "Average: " << sum * 1.0 / count << endl;
   cout << "Negative values: " << negatives << endl;
   if (found_negative)
   {
      cout << "First negative: " + first_negative << endl;
   }
   return 0;
}
