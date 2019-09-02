#include "queue.h"

Queue::Queue()
{
   const int INITIAL_CAPACITY = 5;
   buffer = new string[INITIAL_CAPACITY];
   capacity = INITIAL_CAPACITY;
   head = 0;
   tail = 0;
   len = 0;
}

void Queue::push(string element)
{
   grow_if_necessary();
   buffer[tail] = element;
   tail = (tail + 1) % capacity;
   len++;
}

string Queue::front() const
{
   return buffer[head];
}

void Queue::pop()
{
   head = (head + 1) % capacity;
   len--;
}

int Queue::size() const
{
   return len;
}

void Queue::grow_if_necessary()
{
   if (len == capacity)
   {
      int larger_capacity = 2 * capacity;
      string* larger_buffer = new string[larger_capacity];
      for (int i = 0; i < len; i++) 
      { 
         larger_buffer[i] = buffer[(head + i) % capacity]; 
      }      
      buffer = larger_buffer;
      capacity = larger_capacity;
      head = 0;
      tail = len;
   }
}
