#include "vector.h"

Vector::Vector()
{
   const int INITIAL_CAPACITY = 5;
   buffer = new int[INITIAL_CAPACITY];
   capacity = INITIAL_CAPACITY;
   len = 0;
}

int Vector::size() const
{
   return len;
}

int& Vector::at(int k)
{
   return buffer[k];
}

void Vector::push_back(int element)
{
   grow_if_necessary();
   buffer[len] = element;
   len++;
}

void Vector::insert(int k, int element)
{
   grow_if_necessary();
   len++;
   
   for (int i = len - 1; i > k; i--)
   {
      buffer[i] = buffer[i - 1];
   }

   buffer[k] = element;
}

void Vector::erase(int k)
{
   for (int i = k + 1; i < len; i++)
   {
      buffer[i - 1] = buffer[i];
   }   
   len--; 
}

void Vector::grow_if_necessary()
{
   if (len == capacity)
   {
      capacity = 2 * capacity;
      int* larger_buffer = new int[capacity];
      for (int i = 0; i < len; i++) 
      { 
         larger_buffer[i] = buffer[i]; 
      }      
      buffer = larger_buffer;
   }
}
