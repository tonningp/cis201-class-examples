#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <queue>
#include <sstream>
#include <vector>

using namespace std;

/**
   Create a temporary file name.
*/
string temp_name()
{
   static int file_count = 0;
   ostringstream name;
   name << "temp" << file_count;
   file_count++;
   return name.str();
}

/**
   A generator for strings from standard input.
*/
class WordGen 
{
public:
   string operator()();
};

string WordGen::operator()()
{
   string in;
   if (cin >> in)
   {
      return in;
   }
   return "";
}

void phase1(queue<string>& file_names)
{
   const int max_words = 10;
   WordGen wgen;
   while (cin) 
   {
      // Read max_words into vector, sort them, write to temp file 
      vector<string> a;
      generate_n(back_inserter(a), max_words, wgen);
      sort(a.begin(), a.end());

      vector<string>::iterator p = unique(a.begin(), a.end());
      a.erase(p, a.end());

      string tname = temp_name();
      file_names.push(tname);
      ofstream out_file(tname.c_str());
      copy(a.begin(), a.end(), 
         ostream_iterator<string>(out_file, "\n"));
      out_file.close();
   }
}

void phase2(queue<string>& file_names)
{
   while (file_names.size() > 1) 
   {
      // Merge two temp files into one
      string t1 = file_names.front();
      file_names.pop();
      string t2 = file_names.front();
      file_names.pop();

      ifstream f1(t1.c_str());
      ifstream f2(t2.c_str());
      string tname = temp_name();
      ofstream out_file(tname.c_str());

      merge(istream_iterator<string>(f1), 
         istream_iterator<string>(),
         istream_iterator<string>(f2), 
         istream_iterator<string>(),
         ostream_iterator<string>(out_file, "\n"));

      f1.close();
      f2.close();
      out_file.close();

      // Now remove duplicates from resulting file
      ifstream in_file(tname.c_str());
      string tname2 = temp_name();
      ofstream out_file2(tname2.c_str());

      unique_copy(istream_iterator<string>(in_file), 
         istream_iterator<string>(),
         ostream_iterator<string>(out_file2, "\n"));

      in_file.close();
      out_file2.close();
      file_names.push(tname2);
   }
}

int main()
{
   queue<string> file_names;

   phase1(file_names);
   phase2(file_names);

   string tname = file_names.front();
   ifstream in_file(tname.c_str());
   copy(istream_iterator<string>(in_file),
      istream_iterator<string>(),
      ostream_iterator<string>(cout, "\n"));

   return 0;
}
