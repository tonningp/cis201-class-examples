#include "string.h"
#include <cstring>

String::String()
{
   len = 0;
   buffer = nullptr;
}

String::String(const char s[])
{
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
   delete[] buffer;
}

void String::print(ostream& out) const
{
   for (int i = 0; i < len; i++)
   {
      out << buffer[i];
   }
}
