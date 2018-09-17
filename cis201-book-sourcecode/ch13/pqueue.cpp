#include <iostream>
#include <queue>

using namespace std;

class WorkOrder
{
public:
   WorkOrder(int priority, string description);
   int get_priority() const;
   string get_description() const;
private:
   int priority;
   string description;
};

WorkOrder::WorkOrder(int pr, string descr)
{
   priority = pr;
   description = descr;
}

int WorkOrder::get_priority() const
{
   return priority;
}

string WorkOrder::get_description() const
{
   return description;
}

bool operator<(WorkOrder a, WorkOrder b)
{
   return a.get_priority() < b.get_priority();
}

int main()
{
   priority_queue<WorkOrder> tasks;
   tasks.push(WorkOrder(2, "Shampoo carpets"));
   tasks.push(WorkOrder(3, "Empty trash"));
   tasks.push(WorkOrder(2, "Water plants"));
   tasks.push(WorkOrder(1, "Remove pencil sharpener shavings"));
   tasks.push(WorkOrder(4, "Replace light bulb"));
   tasks.push(WorkOrder(9, "Fix overflowing sink"));
   tasks.push(WorkOrder(1, "Clean coffee maker"));
   tasks.push(WorkOrder(5, "Order cleaning supplies"));

   while (tasks.size() > 0)
   {
      WorkOrder task = tasks.top();
      tasks.pop();
      cout << task.get_priority() << " - " 
         << task.get_description() << "\n";
   }
   return 0;
}
