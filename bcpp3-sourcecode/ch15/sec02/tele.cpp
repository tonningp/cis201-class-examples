#include <iostream>
#include <unordered_map>
#include <utility>
#include <string>
#include <vector>

using namespace std;

/**
   TelephoneDirectory maintains a map of name/number pairs.
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
   int find_entry(string name) const;

   /**
      Print all entries.
   */
   void print_all() const;
private:
   unordered_map<string, int> database;
};

void TelephoneDirectory::add_entry(string name, int number) 
{
   database[name] = number;
}

int TelephoneDirectory::find_entry(string name) const
{
   auto pos = database.find(name);
   if (pos == database.end())
   {
      return 0; // Not found
   }
   else
   {
      return pos->second;
   }
}

void TelephoneDirectory::print_all() const
{
   for (auto pos = database.begin(); pos != database.end(); pos++)
   {
      cout << pos->first << ": " << pos->second << endl;
   }
}

int main()
{
   TelephoneDirectory data;
   data.add_entry("Fred", 7235591);
   data.add_entry("Mary", 3841212);
   data.add_entry("Sarah", 3841212);
   cout << "Number for Fred: " << data.find_entry("Fred") << endl;
   cout << "All names and numbers:" << endl;
   data.print_all();
   return 0;
}
