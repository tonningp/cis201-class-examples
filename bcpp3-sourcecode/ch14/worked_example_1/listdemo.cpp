#include <string>
#include <iostream>
#include "list.h"

using namespace std;

int main()
{  
   List<string> names;

   names.push_back("Tom");
   names.push_back("Diana");
   names.push_back("Harry");
   names.push_back("Juliet");

   // Add a value in fourth place

   List<string>::Iterator pos = names.begin();
   pos++;
   pos++;
   pos++;

   names.insert(pos, "Romeo");

   // Remove the value in second place

   pos = names.begin();
   pos++;

   names.erase(pos);

   // Print all values

   for (pos = names.begin(); pos != names.end(); pos++)
   {
      cout << *pos << " ";
   }
   cout << endl;

   // Make a copy
   
   List<string> names2 = names; 

   // Print with range-based for loop
   
   for (auto element : names2)
   {
      cout << element << " ";
   }
   cout << endl;

   return 0;
}

