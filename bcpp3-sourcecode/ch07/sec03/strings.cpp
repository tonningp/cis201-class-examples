#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>

using namespace std;

/**
   Makes an uppercase version of a string.
   @param str a string
   @return a string with the characters in str converted to uppercase
*/
string uppercase(string str)
{
   string result = str; // Make a copy of str
   for (int i = 0; i < result.length(); i++)
   {
      result[i] = toupper(result[i]); // Convert each character to uppercase
   }
   return result;
}

int main()
{
   /*
     To print character values in decimal, you must convert them to int.
   */
   cout << "Some common char values:" << endl;
   cout << "The letter H: " << static_cast<int>('H') << endl;
   cout << "The digit 0: " << static_cast<int>('0') << endl;
   cout << "The space character: " << static_cast<int>(' ') << endl;
   cout << "The newline character: " << static_cast<int>('\n') << endl;
   cout << endl;

   const char* char_pointer = "Harry";
   cout << "char_pointer points to: " << *char_pointer << endl;
   cout << "Or in decimal: " << static_cast<int>(*char_pointer) << endl;
   cout << "Here is the zero terminator: "
      << static_cast<int>(*(char_pointer + 5)) << endl;

   char char_array[] = "Harry";
   cout << "Here is the zero terminator: "
      << static_cast<int>(char_array[5]) << endl;
   char_array[0] = 'L';
   cout << "Now char_array holds " << char_array << endl;
   cout << endl;

   string year = "2012"; // A C++ string
   char_pointer = year.c_str(); // Converted to char*
   int y = atoi(char_pointer); // atoi requires a C style string   
   cout << "string " << year << " converted to an int: " << y << endl;

   string name = "Harry";
   string sub3 = name.substr(3, 1);
   char ch3 = name[3];
   cout << "Substring of length 1 at index 3: " << sub3 << endl;
   cout << "Substring of length 1 at index 3: " << ch3 << endl;
   name[3] = 'd';
   cout << "After changing name[3]: " << name << endl;
   cout << "Uppercase: " << uppercase(name) << endl;
   
   return 0;
}
