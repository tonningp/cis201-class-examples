#include <string>
#include <iostream>
#include <sstream>


/** 
   Converts an integer value to a string, e.g. 3 -> "3".
   @param s an integer value
   @return the equivalent string
*/   
std::string int_to_string(int n)
{  
   std::ostringstream outstr;
   outstr << n;
   return outstr.str();
}

/**
   Reads a time from standard input in the format hh:mm or 
   hh:mm am or hh:mm pm.
   @param hours filled with the hours
   @param minutes filled with the minutes
*/
void read_time(int& hours, int& minutes)
{  
   std::string line;
   std::getline(std::cin, line);
   std::istringstream instr(line);

   instr >> hours;

   minutes = 0;

   char ch;
   instr.get(ch);

   if (ch == ':')
      instr >> minutes;
   else
      instr.unget();

   std::string suffix;
   instr >> suffix;

   if (suffix == "pm")
      hours = hours + 12;
}

/** 
   Computes a string representing a time.
   @param hours the hours (0...23)
   @param minutes the minutes (0...59)
   @param military true for military format, 
   false for am/pm format                
*/
std::string time_to_string(int hours, int minutes, bool military)
{  
   std::string suffix;
   if (!military)
   {  if (hours < 12)
         suffix = "am";
      else
      {  suffix = "pm";
         hours = hours - 12;
      }
      if (hours == 0) hours = 12;
   }
   std::string result = int_to_string(hours) + ":";
   if (minutes < 10) result = result + "0";
   result = result + int_to_string(minutes);
   if (!military)
      result = result + " " + suffix;
   return result;
}

int main()
{  
   std::cout << "Please enter the time: ";

   int hours;
   int minutes;

   read_time(hours, minutes);

   std::cout << "Military time: " 
      << time_to_string(hours, minutes, true) << "\n";
   std::cout << "Using am/pm: " 
      << time_to_string(hours, minutes, false) << "\n";

   return 0;
}

