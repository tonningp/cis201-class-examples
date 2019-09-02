#ifndef TASK_H
#define TASK_H

#include <string>

using namespace std;

class Task
{
public:
   Task(string description, int priority);  
   string get_description() const;
   int get_priority() const;
private:
   string description;
   int priority;
};

bool operator<(const Task& a, const Task& b);

#endif
