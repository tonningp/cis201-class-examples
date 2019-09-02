/*
   This program prints the frequencies of all words in "Alice in Wonderland".
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <string>

using namespace std;

/**
   Removes characters from a string that are not letters.
   @param s a string
   @return a string with all the letters from s
*/
string clean(const string& s)
{
   string r = "";
   for (int i = 0; i < s.length(); i++)
   {
      char c = s[i];
      if ('a' <= c && c <= 'z') // Append lowercase letters
      {
         r = r + c;
      }
      else if ('A' <= c && c <= 'Z') // If uppercase, turn to lowercase
      {
         c = c - 'A' + 'a';
         r = r + c;
      }
   }
   return r;
}

int main()
{
   map<string, int> frequencies;
   fstream in("../../alice.txt");
   string word;
   while (in >> word)
   {
      word = clean(word);    

      // Get an iterator to the old frequency count

      auto pos = frequencies.find(word);

      // If there was none, put 1; otherwise, increment the count

      if (pos == frequencies.end())
      {
         frequencies[word] = 1;
      }
      else
      {
         pos->second++;
      }
   }

   // Print all words and counts

   for (auto p = frequencies.begin(); p != frequencies.end(); p++)
   {
      cout << setw(20) << left << p->first << setw(10) << right
         << p->second << endl;
   }
   return 0;
}
