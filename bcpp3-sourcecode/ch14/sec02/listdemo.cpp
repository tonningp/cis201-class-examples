#include <string>
#include <iostream>
#include "list.h"

using namespace std;

int main()
{  
   List names;

   names.push_back("Tom");
   names.push_back("Diana");
   names.push_back("Harry");
   names.push_back("Juliet");

   // Add a value in fourth place

   Iterator pos = names.begin();
   pos.next();
   pos.next();
   pos.next();

   names.insert(pos, "Romeo");

   // Remove the value in second place

   pos = names.begin();
   pos.next();

   names.erase(pos);

   // Print all values

   for (pos = names.begin(); !pos.equals(names.end()); pos.next())
   {
      cout << pos.get() << endl;
   }

   return 0;
}

