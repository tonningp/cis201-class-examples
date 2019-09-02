#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>

using namespace std;

unordered_set<string> read_words(string filename)
{
   ifstream in(filename);
   unordered_set<string> result;
   string input;
   while (in >> input)
   {
      // Make letters lowercase and split at non-letters before adding to set
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
   unordered_set<string> dictionary = read_words("../../words.txt");
   unordered_set<string> book = read_words("../../alice.txt");

   // Iterate over all words in the book

   for (auto iter = book.begin(); iter != book.end(); iter++)
   {
      string word = *iter;

      // Print the word if it is not in the dictionary

      if (dictionary.count(word) == 0)
      {
         cout << word << endl;
      }
   }
}
