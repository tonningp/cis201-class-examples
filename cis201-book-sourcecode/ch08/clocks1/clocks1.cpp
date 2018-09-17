#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

#include "clock.h"

int main()
{
   Clock clock1(true);
   Clock clock2(false);

   bool more = true;
   while (more)
   {
      cout << "Military time is "
         << clock1.get_hours() << ":"
         << setw(2) << setfill('0') 
         << clock1.get_minutes() 
         << setfill(' ') << "\n";
      cout << "am/pm time is "
         << clock2.get_hours() << ":"
         << setw(2) << setfill('0') 
         << clock2.get_minutes() 
         << setfill(' ') << "\n";

      cout << "Try again? (y/n) ";
      string input;
      getline(cin, input);
      if (input != "y") more = false;
   }
   return 0;
}

