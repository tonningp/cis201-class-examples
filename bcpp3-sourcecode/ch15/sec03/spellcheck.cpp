#include <iostream>
#include <fstream>
#include <string>
#include "hashtable.h"

using namespace std;

HashTable read_words(string filename)
{
   ifstream in(filename);
   const int BUCKETS = 101;
   HashTable result(BUCKETS);
   string input;
   while (in >> input)
   {
      // Make letters lowercase and split at non-letters
      string word;
      for (int i = 0; i < input.length(); i++)
      {
         if ('a' <= input[i] && input[i] <= 'z')
         {
            word.push_back(input[i]);
         }
         else if ('A' <= input[i] && input[i] <= 'Z')
         {
            word.push_back(input[i] + 'a' - 'A');
         }
         else
         {
            result.insert(word);
            word = "";
         }
      }
      result.insert(word);
   }
   // An empty word might have been inserted if an input had
   // non-letter characters that were adjacent or at the beginning
   // or end of the input.
   result.erase("");

   return result;
}

int main()
{
   HashTable dictionary = read_words("../../words.txt");
   HashTable book = read_words("../../alice.txt");
   for (Iterator iter = book.begin(); !iter.equals(book.end()); iter.next())
   {
      if (dictionary.count(iter.get()) == 0)
      {
         cout << iter.get() << endl;
      }
   }
}
