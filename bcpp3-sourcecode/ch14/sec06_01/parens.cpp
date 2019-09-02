#include <iostream>
#include <stack>
#include <string>

using namespace std;

/*
   This program uses a stack to check whether an expression has balanced 
   parentheses.
*/
int main()
{
   string expression;
   cout << "Enter an expression with { [ ( ) ] }: ";
   getline(cin, expression);
   stack<string> parens;

   for (int i = 0; i < expression.length(); i++)
   {
      string ch = expression.substr(i, 1);
      if (ch == "(" || ch == "[" || ch == "{")
      {
         parens.push(ch);
      }
      else if (ch == ")" || ch == "]" || ch == "}")
      {
         if (parens.size() == 0)
         {
            cout << "Not balanced." << endl;
            return 0;
         }
         string open = parens.top();
         if ((open == "(" && ch == ")"
               || open == "[" && ch == "]"
               || open == "{" && ch == "}"))
         {
            parens.pop();
         }
         else
         {
            cout << "Not balanced." << endl;
            return 0;
         }         
      }
   }
   if (parens.size() == 0) 
   { 
      cout << "Balanced." << endl;
   }
   else
   { 
      cout << "Not balanced." << endl;
   }
   return 0;
}
