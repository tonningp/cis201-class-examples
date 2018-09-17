#include <iostream>
#include "address.h"

using namespace std;

Address::Address() {}

Address::Address(string n, string s,
   string c, string st, string z)
{  
   name = n;
   street = s;
   city = c;
   state = st;
   zip = z;
}   

void Address::print() const
{  
   cout << name << "\n" << street << "\n"
      << city << ", " << state << " " << zip << "\n"; 
}
