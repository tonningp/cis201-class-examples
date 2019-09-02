#ifndef QUEUE_H
#define QUEUE_H

#include <string>

using namespace std;

class Node
{
private:
   string data;
   Node* next;
friend class Queue;   
};


/**
   An implementation of a queue as a sequence of nodes.
*/
class Queue
{
public:   
   /** 
      Constructs an empty queue.
   */
   Queue();

   /**
      Adds an element to the tail of the queue.
      @param element the element to add
   */
   void push(string element);

   /**
      Yields the element from the head of the queue.
      @return the head element
   */
   string front() const;

   /**
      Removes the element from the head of the queue.
   */
   void pop();

   /**
      Yields the number of elements in this queue.
      @return the size
   */
   int size() const;
  
private:  
   Node* first;
   Node* last;
   int len;
};

#endif
