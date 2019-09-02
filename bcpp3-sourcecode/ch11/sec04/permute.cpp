#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
   Generates all permutations of the characters in a string.
   @param word a string
   @return a vector that is filled with all permutations 
   of the word
*/
vector<string> generate_permutations(string word)
{
   vector<string> result;
   if (word.length() == 0) 
   {
      result.push_back(word); // The empty string has only itself as a permutation
      return result;
   }

   for (int i = 0; i < word.length(); i++)
   {
      string shorter_word = word.substr(0, i)
         + word.substr(i + 1); // The word without the ith letter
      vector<string> shorter_permutations
         = generate_permutations(shorter_word);

      // Add the ith letter to the front of all permutations of the shorter word
      for (int j = 0; j < shorter_permutations.size(); j++)
      {
         string longer_word = word[i] + shorter_permutations[j];
         result.push_back(longer_word);
      }   
   }
   return result;
}

int main()
{
   cout << "Enter a string: ";
   string input;
   getline(cin, input);   
   vector<string> v = generate_permutations(input);
   for (int i = 0; i < v.size(); i++)
   {
      cout << v[i] << endl;
   }
   return 0;
}
