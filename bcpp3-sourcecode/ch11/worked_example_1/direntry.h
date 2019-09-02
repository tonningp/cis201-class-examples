#ifndef DIRENTRY_H
#define DIRENTRY_H

#include <string>
#include <vector>

using namespace std;

class DirectoryEntry
{
public:
   /**
      Constructs a directory entry representing a directory.
   */
   DirectoryEntry(string directory_name);
   /**
      Yields the children of this directory.
   */
   vector<DirectoryEntry> children() const;
   /**
      Checks whether this entry represents a directory.
   */
   bool is_directory() const;
   /**
      Yields the name of this entry.
   */
   string name() const;
   /**
      Yields the extension of this entry, or "" if this entry
      has no extension.
   */
   string extension() const;
private:
   DirectoryEntry();
   DirectoryEntry child(string name, int childtype) const;
   
   string entryname;
   int type; 
};

#endif
