#ifndef ADDRESS_H
#define ADDRESS_H

#include <string>

using namespace std;

/**
   Describes a mailing address.
*/
class Address
{  
public:  
   Address();
   Address(string n, string s,
      string c, string st, string z);
   /**
      Prints the address.
   */
   void print() const;
private:
   string name;
   string street;
   string city;
   string state;
   string zip;
};

#endif
