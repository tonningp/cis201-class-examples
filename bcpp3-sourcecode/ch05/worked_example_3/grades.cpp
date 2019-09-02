#include <iostream>
#include <string>

using namespace std;

/**
   Converts a letter grade to a number.
   @param grade a letter grade (A+, A, A-, ..., D-, F)
   @return the equivalent number grade
*/
double grade_to_number(string grade)
{
   double result = 0;
   string first = grade.substr(0, 1);
   if (first == "A") { result = 4; }
   else if (first == "B") { result = 3; }
   else if (first == "C") { result = 2; }
   else if (first == "D") { result = 1; }
   if (grade.length() > 1)
   {
      if (grade.substr(1, 1) == "+")
      {
         result = result + 0.3;
      }
      else 
      {
         result = result - 0.3;
      }
   }
   return result;
}

/**
   Converts a number to the nearest letter grade.
   @param x a number between 0 and 4.3
   @return the nearest letter grade
*/
string number_to_grade(double x)
{
   if (x >= 4.15) { return "A+"; }
   if (x >= 3.85) { return "A"; }
   if (x >= 3.5) { return "A-"; }
   if (x >= 3.15) { return "B+"; }
   if (x >= 2.85) { return "B"; }
   if (x >= 2.5) { return "B-"; }
   if (x >= 2.15) { return "C+"; }
   if (x >= 1.85) { return "C"; }
   if (x >= 1.5) { return "C-"; }
   if (x >= 1.15) { return "D+"; }
   if (x >= 0.85) { return "D"; }
   if (x >= 0.5) { return "D-"; }
   return "F";
}

/**
   Returns the smaller of two numbers.
   @param x a number
   @param y a number
   @return the smaller of x and y
*/
double min(double x, double y) 
{ 
   if (x < y) 
   { 
      return x; 
   } 
   else 
   { 
      return y; 
   }
}

/**
   Processes one line of input.
   @return true if the sentinel was not encountered
*/
bool process_line()
{
   cout << "Enter four grades or Q to quit: ";
   string g1;
   cin >> g1;
   if (g1 == "Q") { return false; }
   string g2;
   string g3;
   string g4;
   cin >> g2 >> g3 >> g4;
   double x1 = grade_to_number(g1);
   double x2 = grade_to_number(g2);
   double x3 = grade_to_number(g3);
   double x4 = grade_to_number(g4);
   double xlow = min(min(x1, x2), min(x3, x4));
   double avg = (x1 + x2 + x3 + x4 - xlow) / 3;
   cout << number_to_grade(avg) << endl;
   return true;
}

int main()
{
   while (process_line())
   {
   }
   return 0;
}

