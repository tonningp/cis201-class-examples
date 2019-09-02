#include <iostream>

using namespace std;

/**
   Prints a string in a box.
   @param contents the string to print in a box
*/
void box_string(string contents)
{
   int n = contents.length();
   // Print the top row
   for (int i = 0; i < n + 2; i++) { cout << "-"; }
   cout << endl;
   cout << "!" << contents << "!" << endl;
   // Print the bottom row
   for (int i = 0; i < n + 2; i++) { cout << "-"; }
   cout << endl;
}

int main()
{
   box_string("Hello");
   box_string("World");
   return 0;
}
