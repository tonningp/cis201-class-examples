#include <stack>
#include <iostream>
#include <cstdlib>

using namespace std;

int main() 
{
   stack<int> values;
   string input;

   while (cin >> input)
   {   
      if (input == "+" || input == "-" || input == "*" || input == "/") 
      {
         int second = values.top();
         values.pop();
         int first = values.top();
         values.pop();
         if (input == "+") 
            values.push(first + second);
         else if (input == "-") 
            values.push(first - second);
         else if (input == "*") 
            values.push(first * second);
         else 
            values.push(first / second);
      }
      else if (input == "p") 
         cout << values.top() << "\n";
      else if (input == "q")
         return 0;
      else // convert input to integer
         values.push(atoi(input.c_str()));
   }
}
