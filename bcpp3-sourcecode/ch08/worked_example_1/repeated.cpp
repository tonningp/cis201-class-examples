#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

using namespace std;

/**
   Checks whether a given line has repeated words (such as "the the")
   @param line a line of text
   @return true if the line contains repeated words
*/
bool has_repeated_words(string line)
{
   istringstream strm;
   strm.str(line); // This string stream reads the contents of the line
   string previous_word = "";
   string word; 
   while (strm >> word) // For each word in the line
   {
      if (word == previous_word) // Found a duplicate
      {
         return true;
      }
      else // Remember this word for the next iteration
      {
         previous_word = word;
      }
   }
   return false;
}

int main()
{
   string filename;
   cout << "Enter filename: ";
   cin >> filename;
   ifstream in_file;
   in_file.open(filename);
   
   int line_number = 0;
   string line;
   while (getline(in_file, line)) // For each line in the file
   {
      line_number++;
      // Print line if it has repeated words
      if (has_repeated_words(line)) 
      {
         cout << setw(7) << line_number << ":" << line << endl;
      }
   }
   return 0;
}
