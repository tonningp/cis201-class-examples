#ifndef MAXHEAP_H
#define MAXHEAP_H

#include <vector>

using namespace std;

/**
   This class implements a heap.
*/
template<typename T>
class MaxHeap
{
public:
   /**
      Constructs an empty heap.
   */
   MaxHeap();

   /**
      Adds a new element to this heap.
      @param element the element to add
   */
   void push(T element);

   /**
      Gets the maximum element stored in this heap.
      @return the maximum element
   */
   T top() const;

   /**
      Removes the maximum element from this heap.
   */
   void pop();

   /**
      Gets the size of this heap.
      @return the size
   */
   int size() const;
private:
   /**
      Turns the tree back into a heap, provided only the root 
      node violates the heap condition.
   */
   void fix_heap();

   /**
      Returns the index of the left child.
      @param index the index of a node in this heap
      @return the index of the left child of the given node
   */
   int get_left_child_index(int index) const;

   /**
      Returns the index of the right child.
      @param index the index of a node in this heap
      @return the index of the right child of the given node
   */
   int get_right_child_index(int index) const;

   /**
      Returns the index of the parent.
      @param index the index of a node in this heap
      @return the index of the parent of the given node
   */
   int get_parent_index(int index) const;

   /**
      Returns the value of the left child.
      @param index the index of a node in this heap
      @return the value of the left child of the given node
   */
   T get_left_child(int index) const;

   /**
      Returns the value of the right child.
      @param index the index of a node in this heap
      @return the value of the right child of the given node
   */
   T get_right_child(int index) const;

   /**
      Returns the value of the parent.
      @param index the index of a node in this heap
      @return the value of the parent of the given node
   */
   T get_parent(int index) const;
   
   vector<T> elements;   
};

template<typename T>
MaxHeap<T>::MaxHeap()
{
   T dummy;
   elements.push_back(dummy); 
}

template<typename T>
void MaxHeap<T>::push(T new_element)
{
   // Add a new leaf
   T dummy;
   elements.push_back(dummy);
   int index = elements.size() - 1;
      
   // Demote parents that are smaller than the new element
   while (index > 1 && get_parent(index) < new_element) 
   {
      elements[index] = get_parent(index);
      index = get_parent_index(index);
   }

   // Store the new element into the vacant slot
   elements[index] = new_element;
}

template<typename T>
T MaxHeap<T>::top() const
{
   return elements[1];
}

template<typename T>
void MaxHeap<T>::pop()
{
   // Remove last element
   int last_index = elements.size() - 1;
   T last = elements[last_index];
   elements.pop_back();
   if (last_index > 1)
   {
      elements[1] = last;
      fix_heap();     
   }
}

template<typename T>
void MaxHeap<T>::fix_heap()
{
   T root = elements[1];
   
   int last_index = elements.size() - 1;
   // Promote children of removed root while they are smaller than root     
   int index = 1;
   bool done = false;
   while (!done)
   {
      int child_index = get_left_child_index(index);
      if (child_index <= last_index)
      {
         // Get larger child 
         
         // Get left child first
         T child = get_left_child(index);
         
         // Use right child instead if it is larger
         if (get_right_child_index(index) <= last_index 
            && child < get_right_child(index))
         {
            child_index = get_right_child_index(index);
            child = get_right_child(index);
         }
         
         // Check if larger child is larger than root
         if (root < child) 
         {
            // Promote child
            elements[index] = child;
            index = child_index;
         }
         else
         {
            // Root is larger than both children
            done = true;
         }
      }
      else 
      {
         // No children
         done = true; 
      }
   }
   
   // Store root element in vacant slot
   elements[index] = root;
}

template<typename T>
int MaxHeap<T>::size() const
{
   return elements.size() - 1;
}

template<typename T>
int MaxHeap<T>::get_left_child_index(int index) const
{
   return 2 * index;
}

template<typename T>
int MaxHeap<T>::get_right_child_index(int index) const
{
   return 2 * index + 1;
}

template<typename T>
int MaxHeap<T>::get_parent_index(int index) const
{
   return index / 2;
}

template<typename T>
T MaxHeap<T>::get_left_child(int index) const
{
   return elements[2 * index];
}

template<typename T>
T MaxHeap<T>::get_right_child(int index) const
{
   return elements[2 * index + 1];
}

template<typename T>
T MaxHeap<T>::get_parent(int index) const
{
   return elements[index / 2];
}

#endif
