#include <iostream>
#include <unordered_set>

#include "task.h"

using namespace std;

int main()
{
   unordered_set<Task> tasks;
   tasks.insert(Task("Clean desk", 9));
   tasks.insert(Task("Sweep floor", 2));
   tasks.insert(Task("Clean desk", 9));
   for (auto iter = tasks.begin(); iter != tasks.end(); iter++)
   {
      cout << iter->get_description() << " " << iter->get_priority()
         << endl;
   }
   
   return 0;
}
