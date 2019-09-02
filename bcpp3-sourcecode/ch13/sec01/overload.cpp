#include <iostream>
#include <iomanip>
#include "time.h"

using namespace std;

/**
   Computes a point in time that is some number of minutes away.
   @param a a point in time
   @param minutes the minutes to add
   @return a point in time that is the given minutes later than a
*/
Time operator+(Time a, int minutes)
{
   int result_minutes = a.get_hours() * 60 + a.get_minutes() + minutes;
   return Time((result_minutes / 60) % 24, result_minutes % 60);
}

/**
   Computes the number of minutes between two points in time.
   @param a a point in time
   @param b another point in time
   @return the number of minutes that a is away from b
*/
int operator-(Time a, Time b)
{
   return a.get_hours() * 60 + a.get_minutes()
      - b.get_hours() * 60 - b.get_minutes();
}

/**
   Compares two points in time.
   @param a a point in time
   @param b another point in time
   @return true if they are the same
*/
bool operator==(Time a, Time b)
{
   return a - b == 0;
}

/**
   Compares two points in time.
   @param a a point in time
   @param b another point in time
   @return true if they are not the same
*/
bool operator!=(Time a, Time b)
{
   return a - b != 0;
}

/**
   Compares two points in time.
   @param a a point in time
   @param b another point in time
   @return true if a comes before b
*/
bool operator<(Time a, Time b)
{
   return a - b < 0;
}

/**
   Prints a Time object.
   @param out an output stream
   @param a a point in time
   @return out
*/
ostream& operator<<(ostream& out, Time a)
{
   out << a.get_hours() << ":"
      << setw(2) << setfill('0')
      << a.get_minutes();
   return out;
}

/**
   Reads a Time object.
   @param in an input stream
   @param a a variable holding a point in time
   @return in
*/
istream& operator>>(istream& in, Time& a)
{
   int hours;
   char separator;
   int minutes;
   in >> hours;
   in.get(separator); // Read : character
   in >> minutes;
   a = Time(hours, minutes);
   return in;
}

int main()
{
   Time too_early(6, 0);
   Time wake_up = too_early + 45;
   cout << "Wake up at: " << wake_up << endl;
   cout << "Current time: ";
   Time now;
   cin >> now;
   Time noon(12, 0);
   if (now < wake_up) { cout << "Too early!"; }
   if (now == noon) { cout << "Time for lunch!"; }
   cout << "Minutes to lunch: " << noon - now << endl;
   
   return 0;
}
