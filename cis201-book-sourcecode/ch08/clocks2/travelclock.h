#include <string>

using namespace std;

#include "clock.h"

class TravelClock : public Clock
{
public:
   /**
      Constructs a travel clock that can tell the time
      at a specified location.
      @param mil true if the clock uses military format
      @param loc the location
      @param diff the time difference from the local time
   */
   TravelClock(bool mil, string loc, int diff);
   string get_location() const;
   int get_hours() const;
private:
   string location;
   int time_difference;
};
