#include <iostream>

using namespace std;

/**
   Prompts a user to enter a value within a given range until the user
   provides a valid input.
   @param low the smallest allowable input
   @param high the largest allowable input
   @return the value provided by the user (between low and high, inclusive)
*/
int read_int_between(int low, int high)
{
   int input;
   do
   {
      cout << "Enter a value between " << low
         << " and " << high << ": ";
      cin >> input;
   }
   while (input < low || input > high);   
   return input;
}

int main()
{
   cout << "Please enter a time; hours, then minutes." << endl;
   int hours = read_int_between(0, 23);
   int minutes = read_int_between(0, 59);
   cout << "You entered " << hours << " hours and "
      << minutes << " minutes." << endl;
   return 0;
}

