#include "travelclock.h"

TravelClock::TravelClock(bool mil, string loc, int diff)
   : Clock(mil)
{
   location = loc;
   time_difference = diff;
   while (time_difference < 0) 
      time_difference = time_difference + 24;
}

string TravelClock::get_location() const
{
   return location;
}

int TravelClock::get_hours() const
{
   int h = Clock::get_hours();
   if (is_military())
      return (h + time_difference) % 24;
   else
   {
      h = (h + time_difference) % 12;
      if (h == 0) return 12;
      else return h;
   }
}
