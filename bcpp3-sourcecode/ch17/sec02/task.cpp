#include "task.h"

Task::Task() {}

Task::Task(string description, int priority)
{
   this->description = description;
   this->priority = priority;
}

string Task::get_description() const
{
   return description;
}

int Task::get_priority() const
{
   return priority;
}

bool operator<(const Task& a, const Task& b)
{
   return a.get_priority() < b.get_priority();
}
