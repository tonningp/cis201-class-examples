#include <sstream>

using namespace std;

double string_to_double(string s)
{  
   istringstream instr(s);
   double x;
   instr >> x;
   return x;
}

int string_to_int(string s)
{  
   istringstream instr(s);
   int x;
   instr >> x;
   return x;
}

string double_to_string(double n)
{  
   ostringstream outstr;
   outstr << n;
   return outstr.str();
}

string int_to_string(int n)
{  
   ostringstream outstr;
   outstr << n;
   return outstr.str();
}
