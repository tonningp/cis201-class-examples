#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
   Tests whether a substring of a string is a palindrome.
   @param s the string to test
   @param start the index of the first character of the substring
   @param end the index of the last character of the substring
   @return true if the substring is a palindrome
*/
bool substring_is_palindrome(string s, int start, int end)
{
   // Separate case for substrings of length 0 and 1
   if (start >= end) { return true; }
   if (s[start] == s[end])
   {
      // Test substring that doesn’t contain the first and last letters
      return substring_is_palindrome(s, start + 1, end - 1);
   }
   else
   {
      return false;
   }
}   

/**
   Tests whether a string is a palindrome. A palindrome
   is equal to its reverse, for example "rotor" or "racecar".
   @param s a string
   @return true if s is a palindrome
*/
bool is_palindrome(string s)
{
   return substring_is_palindrome(s, 0, s.length() - 1);
}

int main()
{
   cout << "Enter a string: ";
   string input;
   getline(cin, input);
   cout << input << " is ";
   if (!is_palindrome(input)) { cout << "not " };
   cout << "a palindrome." << endl;
   return 0;
}
