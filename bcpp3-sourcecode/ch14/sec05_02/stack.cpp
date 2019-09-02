#include "stack.h"

Stack::Stack()
{
   const int INITIAL_CAPACITY = 5;
   buffer = new string[INITIAL_CAPACITY];
   capacity = INITIAL_CAPACITY;
   len = 0;
}

void Stack::push(string element)
{
   grow_if_necessary();
   buffer[len] = element;
   len++;
}

string Stack::top() const
{
   return buffer[len - 1];
}

void Stack::pop()
{
   len--;
}

int Stack::size() const
{
   return len;
}

void Stack::grow_if_necessary()
{
   if (len == capacity)
   {
      capacity = 2 * capacity;
      string* larger_buffer = new string[capacity];
      for (int i = 0; i < len; i++) 
      { 
         larger_buffer[i] = buffer[i]; 
      }      
      buffer = larger_buffer;
   }
}
