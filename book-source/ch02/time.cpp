#include <iostream>

using namespace std;

#include "ccc_time.h"

int main()
{  
   Time wake_up(7, 0, 0);
   wake_up.add_seconds(1000); 
      // A thousand seconds later
   cout << wake_up.get_hours() 
      << ":" << wake_up.get_minutes()
      << ":" << wake_up.get_seconds() << "\n";

   Time now;
   int seconds_left = Time(23, 59, 59).seconds_from(now);

   cout << "There are "
      << seconds_left
      << " seconds left in this day.\n";

   return 0;
}
