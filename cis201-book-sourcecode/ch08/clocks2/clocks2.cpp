#include <iostream>
#include <iomanip>

using namespace std;

#include "travelclock.h"

int main()
{
   Clock clock1(true);
   TravelClock clock2(true, "Rome", 9);
   TravelClock clock3(false, "Tokyo", -7);

   cout << clock1.get_location() << " time is " 
      << clock1.get_hours() << ":"
      << setw(2) << setfill('0') 
      << clock1.get_minutes() 
      << setfill(' ') << "\n";
   cout << clock2.get_location() << " time is " 
      << clock2.get_hours() << ":"
      << setw(2) << setfill('0') 
      << clock2.get_minutes() 
      << setfill(' ') << "\n";
   cout << clock3.get_location() << " time is " 
      << clock3.get_hours() << ":"
      << setw(2) << setfill('0') 
      << clock3.get_minutes() 
      << setfill(' ') << "\n";
   return 0;
}

