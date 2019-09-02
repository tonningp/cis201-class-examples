#include "queue.h"

Queue::Queue()
{  
   first = nullptr;
   last = nullptr;
   len = 0;
}

void Queue::push(string element)
{  
   Node* new_node = new Node;
   new_node->data = element;
   new_node->next = nullptr;
   if (last == nullptr) 
   {
      first = new_node;
   }
   else
   {
      last->next = new_node;
   }
   last = new_node;
   len++;
}

string Queue::front() const
{
   return first->data;
}

void Queue::pop()
{
   Node* to_delete = first;
   first = first->next;
   delete to_delete;
   len--;
}

int Queue::size() const
{
   return len;
}
