#include "stack.h"

Stack::Stack()
{  
   first = nullptr;
   len = 0;
}

void Stack::push(string element)
{  
   Node* new_node = new Node;
   new_node->data = element;
   new_node->next = first;
   first = new_node;
   len++;
}

string Stack::top() const
{
   return first->data;
}

void Stack::pop()
{
   Node* to_delete = first;
   first = first->next;
   delete to_delete;
   len--;
}

int Stack::size() const
{
   return len;
}
