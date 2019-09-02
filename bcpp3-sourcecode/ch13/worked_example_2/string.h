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
   
   String operator+(const String& other) const;
   bool operator==(const String& other) const;

   /**
      Yields the length of this string.
      @return the length
   */
   int length() const;   
   /**
      Yields a substring of this string.
      @param start the position of the first character to copy
      @param length the number of characters to copy
      @return the substring
   */
   String substr(int start, int length) const;
   /**
      Prints this fraction to a stream.
      @param out the output stream
   */
   void print(ostream& out) const;
private:
   char* buffer;
   int len;
};

ostream& operator<<(ostream& out, const String& str);
bool operator!=(const String& s, const String& t);

#endif
