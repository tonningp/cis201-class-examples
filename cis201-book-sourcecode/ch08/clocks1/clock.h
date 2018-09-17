#ifndef CLOCK_H
#define CLOCK_H

#include <string>

using namespace std;

class Clock
{
public:
   /**
      Constructs a clock that can tell the local time.
      @param use_military true if the clock uses military format
   */
   Clock(bool use_military);
   
   /**
      Gets the location of this clock.
      @return the location
   */
   string get_location() const;

   /**
      Gets the hours of this clock.
      @return the hours, in military or am/pm format
   */
   int get_hours() const;

   /**
      Gets the minutes of this clock.
      @return the minutes
   */
   int get_minutes() const;

   /**
      Checks whether this clock uses military format.
      @return true if military format
   */
   bool is_military() const;
private:
   bool military;
};

#endif
