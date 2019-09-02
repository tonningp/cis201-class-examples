#include <iostream>
#include "queue.h"

using namespace std;

int main()
{
   Queue q;
   q.push("Tom");
   q.push("Diana");
   q.push("Harry");

   while (q.size() > 0)
   {
      string name = q.front();
      q.pop();
      cout << name << endl;
   }
   return 0;
}
