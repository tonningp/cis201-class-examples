#include <iostream>
#include "vector.h"

using namespace std;

int main()
{
   Vector numbers;
   numbers.push_back(4);
   numbers.push_back(3);
   numbers.push_back(7);
   numbers.push_back(2);
   numbers.push_back(5);
   numbers.push_back(9);
   for (int i = 0; i < numbers.size(); i++)
   {
      cout << numbers.at(i) << " ";      
   }
   cout << endl;
   return 0;
}
