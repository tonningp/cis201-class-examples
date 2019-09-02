#include "task.h"

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

namespace std
{
   int hash<Task>::operator()(const Task &t) const
   {
      hash<string> string_hash_code;
      int h = string_hash_code(t.get_description())
         + t.get_priority();
      return h;
   }
}

bool operator==(const Task& a, const Task& b)
{
   return a.get_description() == b.get_description()
      && a.get_priority() == b.get_priority();
}
