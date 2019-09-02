#include <iostream>
#include "string.h"

using namespace std;

int spaces(String str)
{
   int count = 0;
   String space(" ");
   for (int i = 0; i < str.length(); i++)
   {
      if (str.substr(i, 1) == space) { count++; }
   }
   return count;
}

int main()
{
   String name("Mary Ann");
   String name2 = name; // Copy constructor
   String name3("Fred");
   name3 = name; // operator=

   int result = spaces(name);
   cout << "Spaces: " << result << endl;
   
   return 0;
} // str and space are destroyed here
