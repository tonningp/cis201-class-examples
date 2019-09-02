#include <string>
#include <list>
#include <iostream>

using namespace std;

int main()
{  
   list<string> names;

   names.push_back("Tom");
   names.push_back("Diana");
   names.push_back("Harry");
   names.push_back("Juliet");

   // Add a value in fourth place

   list<string>::iterator pos = names.begin();
   // Or auto pos = names.begin();
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

   // Print all values with range-based loop

   for (const string& element : names)
   {
      cout << element << " ";
   }
   cout << endl;

   return 0;
}

