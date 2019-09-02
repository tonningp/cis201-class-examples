#include <iostream>
#include <stack>
#include <string>
#include <cstdlib>

using namespace std;

/**
   Tests if a token is an operator.
   @param token the token
   @return true if the token is one of: + - * / ^
*/
bool is_operator(string token)
{  
   return token == "+" || token == "-" || token == "*" || token == "/";
}

/**
   Tests if a token is a digit.
   @param token the token
   @return true if token is one of: 0 1 2 3 4 5 6 7 8 9
*/
bool is_digit(string token)
{  
   return token.length() == 1 && "0" <= token && token <= "9";
}

/**
   Computes the precedence level of an operator.
   @param op the operator
   @return the precedence level (1 = lowest, 3 = highest)
*/
int precedence(string op)
{  
   if (op == "+" || op == "-") { return 1; }
   else if (op == "*" || op == "/") { return 2; }
   else { return 0; }
}

/**
   Prints an error message and exits.
   @param message information about the error
*/
void error(string message)
{  
   cout << "ERROR: " << message << "." << endl;
   exit(1);
}

/** 
    Computes a new value and pushes it on the stack.
    @param num the stack for the operands and result
    @param op the operation to use
*/
void evaluate_top(stack<int>& num, string op)
{  
   if (num.size() == 0) { error("Syntax error"); }
   int y = num.top();
   num.pop();
   if (num.size() == 0) { error("Syntax error"); }
   int x = num.top();
   num.pop();
   int z = 0;
   if (op == "*") { z = x * y; }
   else if (op == "/")
   {  
      if (y == 0) { error("Divide by 0"); }
      else { z = x / y; }
   }
   else if (op == "+") { z = x + y; }
   else if (op == "-") { z = x - y; }
   else { error("Syntax error"); }
   num.push(z);
}

/*
   This program evaluates arithmetic expressions, using two stacks.
*/
int main()
{  
   cout << "Enter an arithmetic expression such as (3+4)*5: ";
   string expression;
   getline(cin, expression);
      
   stack<int> numstack;
   stack<string> opstack;
      
   int pos = 0;
   while (pos < expression.length())
   {  
      string ch = expression.substr(pos, 1);
      pos++;
      if (is_operator(ch))
      {  
         if (opstack.size() == 0) { opstack.push(ch); }
         else
         {  
            string old_op = opstack.top();
            opstack.pop();
            if (precedence(ch) > precedence(old_op)) 
            {
               opstack.push(old_op); 
            }
            else { evaluate_top(numstack, old_op); }
            opstack.push(ch);
         }
      }
      else if (ch == "(") { opstack.push(ch); }
      else if (ch == ")")
      {  
         bool done = false;
         while (!done)
         {  
            if (opstack.size() == 0) { error("No matching ("); }
            string old_op = opstack.top();
            opstack.pop();
            if (old_op == "(") { done = true; }
            else { evaluate_top(numstack, old_op); }
         }
      }
      else if (is_digit(ch))
      {
         int start = pos - 1;
         while (pos < expression.length() 
            && is_digit(expression.substr(pos, 1))) { pos++; }
         string num = expression.substr(start, pos - start);
         numstack.push(stoi(num));
      }
      else if (ch != " ")
      {
         error ("Number, operator, or parenthesis expected.");
      }
   }
   while (opstack.size() > 0)
   {  
      string old_op = opstack.top();
      opstack.pop();
      if (old_op == "(") { error("No matching )"); }
      else { evaluate_top(numstack, old_op); }
   }
   if (numstack.size() == 0) { error("Syntax error"); }
   cout << numstack.top() << endl;
   if (numstack.size() > 1) { error("Syntax error"); }
  
   return 0;
}
