#include <iostream>
#include <queue>
#include "task.h"

using namespace std;

int main()
{
   priority_queue<Task> tasks;
   tasks.push(Task("Shampoo carpets", 2));
   tasks.push(Task("Empty trash", 3));
   tasks.push(Task("Water plants", 2));
   tasks.push(Task("Remove pencil sharpener shavings", 1));
   tasks.push(Task("Replace light bulb", 4));
   tasks.push(Task("Fix overflowing sink", 9));
   tasks.push(Task("Clean coffee maker", 1));
   tasks.push(Task("Order cleaning supplies", 5));

   while (tasks.size() > 0)
   {
      Task most_important = tasks.top();
      tasks.pop();
      cout << most_important.get_priority() << " - " 
         << most_important.get_description() << endl;
   }
   return 0;
}
