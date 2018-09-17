# Instructor Notes
- Pay attention to the Quality Tips and The Productivity Hints
- The Selection Operator Advanced Topic item on page 104 is helpful, spend some time experimenting with this:
```cpp
#include<iostream>
#include<string>

using namespace std;

int main()
{
   int the_question=42;
   string the_answer = the_question == 42 ? "Yes" : "No";

   cout << "Is the answer 42? " << the_answer << endl;

   return 0;
}
```
