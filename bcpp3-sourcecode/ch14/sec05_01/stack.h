#ifndef STACK_H
#define STACK_H

#include <string>

using namespace std;

class Node
{
private:
   string data;
   Node* next;
friend class Stack;   
};


/**
   An implementation of a stack as a sequence of nodes.
*/
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
   Node* first;
   int len;
};

#endif
