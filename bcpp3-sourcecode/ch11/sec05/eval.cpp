#include <iostream>
#include <cctype>

using namespace std;

int term_value();
int factor_value();

/**
   Evaluates the next expression found in cin.
   @return the value of the expression
*/
int expression_value()
{
   int result = term_value();
   bool done = false;
   while (!done)
   {
      char op = cin.get();
      if (op == '+' || op == '-')
      {
         int value = term_value();
         if (op == '+') { result = result + value; }
         else { result = result - value; }
      }
      else { cin.unget(); done = true; }
   }
   return result;
}

/**
   Evaluates the next term found in cin.
   @return the value of the term
*/
int term_value()
{
   int result = factor_value();
   bool done = false;
   while (!done)
   {
      char op = cin.get();
      if (op == '*' || op == '/')
      {
         int value = factor_value();
         if (op == '*') { result = result * value; }
         else { result = result / value; }
      }
      else { cin.unget(); done = true; }
   }
   return result;
}

/**
   Evaluates the next factor found in cin.
   @return the value of the factor
*/
int factor_value()
{
   int result = 0;
   char c = cin.get();
   if (c == '(')
   {
      result = expression_value();
      cin.get(); // Read ")"
   }
   else
   {
      cin.unget();
      cin >> result;
   }
   return result;
}

int main()
{
   cout << "Enter an expression: ";
   cout << expression_value() << endl;
   return 0;
}
