#ifndef STACK_H
#define STACK_H

#include <string>

using namespace std;

class Stack
{
public:   
   /** 
      Constructs an empty stack.
   */
   Stack();

   /**
      Adds an element to the top of the stack.
      @param element the element to add
   */
   void push(string element);

   /**
      Yields the element on the top of the stack.
      @return the top element
   */
   string top() const;

   /**
      Removes the element from the top of the stack.
   */
   void pop();

   /**
      Yields the number of elements in this stack.
      @return the size
   */
   int size() const;
  
private:
   void grow_if_necessary();
   
   string* buffer;
   int len;
   int capacity;
};

#endif
