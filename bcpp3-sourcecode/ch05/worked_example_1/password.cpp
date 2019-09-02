#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

/**
   Returns a string containing one character randomly chosen from a given string.
   @param characters the string from which to randomly choose a character
   @return a substring of length 1, taken at a random index
*/
string random_character(string characters)
{
   int n = characters.length();
   int r = rand() % n;
   return characters.substr(r, 1);
}
   
/**
   Inserts one string into another at a random position.
   @param str the string into which another string is inserted
   @param to_insert the string to be inserted
   @return the result of inserting to_insert into str
*/
string insert_at_random(string str, string to_insert)
{
   int n = str.length();
   int r = rand() % (n + 1);
   return str.substr(0, r) + to_insert + str.substr(r);
}

/**
   Generates a random password.
   @param length the length of the password
   @return a password of the given length with one digit and one 
   special symbol
*/
string make_password(int length)
{
   string password = "";

   // Pick random letters

   for (int i = 0; i < length - 2; i++)
   {
      password = password + random_character("abcdefghijklmnopqrstuvwxyz");
   }

   // Insert two random digits

   string random_digit = random_character("0123456789");
   password = insert_at_random(password, random_digit);
   string random_symbol = random_character("+-*/?!@#$%&");
   password = insert_at_random(password, random_symbol);
   return password;
}

int main()
{
   srand(time(0));
   string result = make_password(8);
   cout << result << endl;
   return 0;
}
