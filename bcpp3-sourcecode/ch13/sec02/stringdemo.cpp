#include <iostream>
#include "string.h"

using namespace std;

/**
   Prints a string repeatedly.
   @param str a string
   @param count the number of times that this string should be printed.
*/
void repeat(String str, int count) // Copy constructor
{
   for (int i = 0; i < count; i++)
   {
      str.print(cout);
   }
   cout << endl;
} // str destroyed here

int main()
{
   String name("Mary");
   String name2 = name; // Copy constructor
   String name3("Fred"); 
   name = name3; // operator=

   repeat(name, 2);
   repeat(name2, 3);
   
   return 0;
} // name3, name2, name destroyed here
