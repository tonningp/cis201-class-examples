#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include "direntry.h"

using namespace std;

void find(DirectoryEntry directory, string extension)
{
   vector<DirectoryEntry> entries = directory.children();
   for (int i = 0; i < entries.size(); i++)
   {
      DirectoryEntry entry = entries[i];
      if (entry.is_directory())
      {
         find(entry, extension);
      }
      else if (entry.extension() == extension)
      {
         cout << entry.name() << endl;
      }
   }
}

int main()
{
   find(DirectoryEntry(".."), "cpp");
}
