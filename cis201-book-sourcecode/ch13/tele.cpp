#include <iostream>
#include <map>
#include <utility>
#include <string>
#include <vector>

using namespace std;

/**
   TelephoneDirectory maintains a map of name/number pairs
   and an inverse multimap of numbers and names.
*/
class TelephoneDirectory 
{
public:
   /**
      Add a new name/number pair to database.
      @param name the new name
      @param number the new number
   */
   void add_entry(string name, int number);

   /**
      Find the number associated with a name.
      @param name the name being searched
      @return the associated number, or zero 
      if not found in database
   */
   int find_entry(string name);

   /**
      Find the names associated with a number.
      @param number the number being searched
      @return the associated names
   */
   vector<string> find_entries(int number);

   /**
      Print all entries.
   */
   void print_all();
private:
   map<string, int> database;
   multimap<int, string> inverse_database;
};

void TelephoneDirectory::add_entry(string name, int number)
{
   database[name] = number;
   inverse_database.insert(make_pair(number, name));
}

int TelephoneDirectory::find_entry(string name)
{
   map<string, int>::iterator p = database.find(name);
   if (p == database.end())
      return 0; // not found
   else
      return p->second;
}

vector<string> TelephoneDirectory::find_entries(int number) 
{
   multimap<int, string>::iterator lower 
      = inverse_database.lower_bound(number);
   multimap<int, string>::iterator upper 
      = inverse_database.upper_bound(number);
   vector<string> result;
   
   for (multimap<int, string>::iterator pos = lower; 
        pos != upper; pos++)
      result.push_back(pos->second);
   return result;
}

void TelephoneDirectory::print_all()
{
   for (map<string, int>::iterator pos = database.begin();
        pos != database.end(); pos++)
   {
      cout << pos->first << ": " << pos->second << "\n";
   }
}

int main()
{
   TelephoneDirectory data;
   data.add_entry("Fred", 7235591);
   data.add_entry("Mary", 3841212);
   data.add_entry("Sarah", 3841212);
   cout << "Number for Fred: " << data.find_entry("Fred") << "\n";
   vector<string> names = data.find_entries(3841212);
   cout << "Names for 3841212: ";
   for (int i = 0; i < names.size(); i++)
      cout << names[i] << " ";
   cout << "\n";
   cout << "All names and numbers:\n";
   data.print_all();
   return 0;
}

