#include "ccc_time.h"
#include "clock.h"

Clock::Clock(bool use_military)
{
   military = use_military;
}

string Clock::get_location() const
{
   return "Local";
}

int Clock::get_hours() const
{
   Time now;
   int hours = now.get_hours();
   if (military) return hours;
   if (hours == 0) 
      return 12;
   else if (hours > 12)
      return hours - 12;
   else
      return hours;
}

int Clock::get_minutes() const
{
   Time now;
   return now.get_minutes();
}

bool Clock::is_military() const
{
   return military;
}
