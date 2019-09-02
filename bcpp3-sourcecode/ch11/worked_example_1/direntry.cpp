#include <string>
#include <cstdlib>
#include <fstream>
#include "direntry.h"

using namespace std;

#ifdef WINDOWS
const string FILE_SEPARATOR = "\\";
#else
const string FILE_SEPARATOR = "/";
#endif   

const int DIRECTORY_TYPE = 0;
const int FILE_TYPE = 1;
   
DirectoryEntry::DirectoryEntry(string name)
{
   entryname = name;
   type = DIRECTORY_TYPE;
}

DirectoryEntry::DirectoryEntry() {}

DirectoryEntry DirectoryEntry::child(string name, int childtype) const
{
   DirectoryEntry result;
   result.type = childtype;
   if (entryname == "")
   {
      result.entryname = name;
   }
   else
   {
      result.entryname = entryname + FILE_SEPARATOR + name;
   }
   return result;
}
   
vector<DirectoryEntry> DirectoryEntry::children() const
{
   vector<DirectoryEntry> result;
   if (is_directory())
   {
#ifdef WINDOWS
      string cmd = "DIR /AD /B" + entryname + " > .__output";
      system(cmd.c_str());
      ifstream in;
      in.open(".__output");
      string line;
      while (getline(in, line))
      {         
         DirectoryEntry entry = child(line, DIRECTORY_TYPE);
         result.push_back(entry);         
      }
      cmd = "DIR /A-D /B" + entryname + " > .__output";
      system(cmd.c_str());
      in.open(".__output");
      while (getline(in, line))
      {
         DirectoryEntry entry = child(line, FILE_TYPE);
         result.push_back(entry);         
      }
      system("DEL .__output");            
#else
      string cmd = "ls -1F " + entryname + " > .__output";
      system(cmd.c_str());
      ifstream in;
      in.open(".__output");
      string line;
      while (getline(in, line))
      {
         string last = line.substr(line.length() - 1);
         if (last == "/")
         {
            DirectoryEntry entry = child(
               line.substr(0, line.length() - 1), DIRECTORY_TYPE);
            result.push_back(entry);         
         }
         else
         {
            if (last == "@" || last == "*" || last == "="
               || last == ">" || last == "|")
            {
               line = line.substr(0, line.length() - 1);
            }
            DirectoryEntry entry = child(line, FILE_TYPE);
            result.push_back(entry);         
         }
      }
      system("rm .__output");
#endif
   }
   return result;
}

bool DirectoryEntry::is_directory() const
{
   return type == DIRECTORY_TYPE;
}

string DirectoryEntry::name() const
{
   return entryname;
}

string DirectoryEntry::extension() const
{
   int i = entryname.length() - 1;
   while (i >= 0 && entryname.substr(i, 1) != FILE_SEPARATOR) 
   {
      if (entryname.substr(i, 1) == ".")
      {
         return entryname.substr(i + 1);
      }
      i--;
   }
   return ""; // No extension
}

