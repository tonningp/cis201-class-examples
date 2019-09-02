#include <cctype>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

using namespace std;

/** 
   Converts a string to a floating-point number, e.g. "3.14" -> 3.14.
   @param s a string representing a floating-point number
   @return the equivalent floating-point number
*/   
double string_to_double(string s)
{
   istringstream stream;
   stream.str(s);
   double x = 0;
   stream >> x;
   return x;
}

/**
   Extracts the country and associated value from an input line.
   @param line a line containing a country name, followed by a number
   @param country the string for holding the country name
   @param value the variable for holding the associated value
   @return true if a line has been read, false at the end of the stream
*/
void read_line(string line, string& country, double& value)
{   
   int i = 0; // Locate the start of the first digit
   while (!isdigit(line[i])) { i++; }
   int j = i - 1; // Locate the end of the preceding word
   while (isspace(line[j])) { j--; }
      
   country = line.substr(0, j + 1); // Extract the country name
   value = string_to_double(line.substr(i)); // Extract the number value
}

int main()
{
   ifstream in1;
   ifstream in2;
   in1.open("worldpop.txt"); // Open input files
   in2.open("worldarea.txt");

   ofstream out;
   out.open("world_pop_density.txt"); // Open output file
   out << fixed << setprecision(2);

   string line1;
   string line2;

   // Read lines from each file
   while (getline(in1, line1) && getline(in2, line2))
   {
      string country;
      double population;
      double area;

      // Split the lines into country and associated value
      read_line(line1, country, population);
      read_line(line2, country, area);

      // Compute and print the population density
      double density = 0;
      if (area != 0) // Protect against division by zero
      {
         density = population * 1.0 / area;
      }
      out << setw(40) << left << country  
         << setw(15) << right << density << endl;      
   }

   return 0;
}
