#include "string.h"
#include <cstring>

String::String()
{
   cout << "Constructing empty string" << endl;
   len = 0;
   buffer = nullptr;
}

String::String(const char s[])
{
   cout << "Constructing \"" << s << "\"" << endl;
   len = strlen(s);
   if (len > 0)
   {
      buffer = new char[len];
      for (int i = 0; i < len; i++)
      {
         buffer[i] = s[i];
      }
   }
   else
   {
      buffer = nullptr;
   }
}

String::String(const String& other)
{
   cout << "Copying \"" << other << "\"" << endl;
   len = other.len;
   if (len > 0)
   {   
      buffer = new char[len];
      for (int i = 0; i < len; i++)
      {
         buffer[i] = other.buffer[i];
      }
   }
   else
   {
      buffer = nullptr;
   }   
}
   
String& String::operator=(const String& other)
{
   cout << "Assigning \"" << other << "\" to \""
      << *this << "\"" << endl;
   if (this != &other)
   {
      delete[] buffer;
      len = other.len;
      if (len > 0)
      {   
         buffer = new char[len];
         for (int i = 0; i < len; i++)
         {
            buffer[i] = other.buffer[i];
         }
      }
      else
      {
         buffer = nullptr;
      }
   }
   return *this;
}

String::~String()
{
   cout << "Destroying \"" << *this << "\"" << endl;
   delete[] buffer;
}

int String::length() const
{
   return len;
}

String String::substr(int start, int length) const
{
   String result;
   if (length > 0)
   {
      result.len = length;
      result.buffer = new char[length];
      for (int i = 0; i < length; i++)
      {
         result.buffer[i] = buffer[start + i];
      }
   }
   return result;
}

String String::operator+(const String& other) const
{
   String result;
   result.len = len + other.len;
   result.buffer = new char[result.len];
   for (int i = 0; i < len; i++)
   {
      result.buffer[i] = buffer[i];
   }
   for (int i = 0; i < other.len; i++)
   {
      result.buffer[len + i] = other.buffer[i];
   }
   return result;
}

bool String::operator==(const String& other) const
{
   if (len != other.len) { return false; }
   for (int i = 0; i < len; i++)
   {
      if (buffer[i] != other.buffer[i]) { return false; }
   }
   return true;
}

void String::print(ostream& out) const
{
   for (int i = 0; i < len; i++)
   {
      out << buffer[i];
   }
}

ostream& operator<<(ostream& out, const String& str)
{
   str.print(out);
   return out;
}

bool operator!=(const String& s, const String& t)
{
   return !(s == t);
}
