#include <iostream>
#include <vector>

using namespace std;

int main()
{  
   vector<double> values;

   cout << "Please enter values, Q to quit:" << endl;
   double input;
   while (cin >> input)
   {  
      values.push_back(input);
   }

   double largest = values[0];
   for (int i = 1; i < values.size(); i++)
   {
      if (values[i] > largest)
      {
         largest = values[i];
      }
   }

   for (int i = 0; i < values.size(); i++)
   {  
      cout << values[i];
      if (values[i] == largest) 
      {
         cout << " <== largest value";
      }
      cout << endl;
   }

   return 0;
}
