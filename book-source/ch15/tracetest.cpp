# include <iostream>
# include "trace.h"

using namespace std;

int main ( ) 
{
   int a = 5;
   Trace one("TraceTest");
   if (a < 10) 
   {
      Trace two("if");
      //...
   } 
   else 
   {
      Trace three("else");
      //...
   }
return 0;
}
