#include "telephone.h"
#include "connection.h"

void Telephone::run(Connection& c)
{
   bool more = true;
   while (more)
   {
      string input;
      getline(cin, input);
      if (input == "H")
         c.hangup();
      else if (input == "Q")
         more = false;
      else if ((input.length() == 1) &&
         (isdigit(input[0]) || input[0] == '#'))
         c.dial(input);
      else
         c.record(input);
   }
}

