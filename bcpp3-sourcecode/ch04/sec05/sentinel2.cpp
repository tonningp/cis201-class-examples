#include <iostream>

using namespace std;

int main()
{  
   double sum = 0;
   int count = 0;
   double value = 0;
   cout << "Enter values, Q to quit: ";
   bool done = false;
   while (!done)
   {  
      cin >> value;
      if (cin.fail())
      {
         done = true;
      }
      else 
      {  
         sum = sum + value;
         count++;
      }
   }
   if (count > 0)
   {
      double average = sum / count;
      cout << "Average: " << average << endl;
   }
   else
   {
      cout << "No data" << endl;
   }
   return 0;
}
