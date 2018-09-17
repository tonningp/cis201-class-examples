#include <string>

using namespace std;

/** 
   Converts a string to a floating-point value, e.g. 
   "3.14" -> 3.14.
   @param s a string representing a floating-point value
   @return the equivalent floating-point value
*/   
double string_to_double(string s);

/** 
   Converts a string to an integer, e.g. 
   "314" -> 314.
   @param s a string representing an integer
   @return the equivalent integer
*/   
int string_to_int(string s);

/** 
   Converts a floating-point value to a string, e.g. 3.14 -> "3.14".
   @param n a floating-point value
   @return the equivalent string
*/   
string double_to_string(double n);

/** 
   Converts an integer to a string, e.g. 3 -> "3".
   @param n an integer
   @return the equivalent string
*/   
string int_to_string(int n);
