#include <iostream>

using namespace std;

int main()
{  
   double sum = 0;
   int count = 0;
   bool more = true;   
   
   while (more)
   {  
      double input;
      cout << "Enter a value, -1 to finish: ";
      cin >> input;
      
      if (input == -1) 
         more = false;
      else
      {  
         sum = sum + input;
         count++;
      }
   }
   
   if (count > 0)
      cout << "Average: " << sum / count << "\n";

   return 0;
}
