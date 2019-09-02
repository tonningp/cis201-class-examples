#ifndef STRING_H
#define STRING_H

#include <iostream>

using namespace std;

class String
{
public:
   String();
   String(const char s[]);
   String(const String& other);
   String& operator=(const String& other);
   ~String();
   
   /**
      Prints this string to a stream.
      @param out the output stream
   */
   void print(ostream& out) const;
private:
   char* buffer;
   int len;
};

#endif
