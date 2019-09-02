#include "time.h"

Time::Time()
{
   hours = 0;
   minutes = 0;
}

Time::Time(int h, int m)
{
   hours = h;
   minutes = m;
}

int Time::get_hours() const
{
   return hours;
}

int Time::get_minutes() const
{
   return minutes;
}
