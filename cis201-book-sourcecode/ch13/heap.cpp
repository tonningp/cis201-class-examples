#include <iostream>
#include <vector>

using namespace std;

/**
   This class implements a heap.
*/
class Heap
{
public:
   /**
      Constructs an empty heap.
   */
   Heap();

   /**
      Adds a new element to this heap.
      @param new_element the element to add
   */
   void push(int new_element);

   /**
      Gets the maximum element stored in this heap.
      @return the maximum element
   */
   int top() const;

   /**
      Removes the maximum element from this heap.
   */
   void pop();

   /**
      Returns the number of elements in this heap.
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
   int get_left_child_index(int index);

   /**
      Returns the index of the right child.
      @param index the index of a node in this heap
      @return the index of the right child of the given node
   */
   int get_right_child_index(int index);

   /**
      Returns the index of the parent.
      @param index the index of a node in this heap
      @return the index of the parent of the given node
   */
   int get_parent_index(int index);

   /**
      Returns the value of the left child.
      @param index the index of a node in this heap
      @return the value of the left child of the given node
   */
   int get_left_child(int index);

   /**
      Returns the value of the right child.
      @param index the index of a node in this heap
      @return the value of the right child of the given node
   */
   int get_right_child(int index);

   /**
      Returns the value of the parent.
      @param index the index of a node in this heap
      @return the value of the parent of the given node
   */
   int get_parent(int index);

   vector<int> elements;
};

Heap::Heap()
{
   elements.push_back(0); 
}

void Heap::push(int new_element)
{
   // Add a new leaf
   elements.push_back(0);
   int index = elements.size() - 1;
      
   // Demote parents that are smaller than the new element
   while (index > 1 
      && get_parent(index) < new_element) 
   {
      elements[index] =  get_parent(index);
      index = get_parent_index(index);
   }

   // Store the new element into the vacant slot
   elements[index] = new_element;
}

int Heap::top() const
{
   return elements[1];
}

void Heap::pop()
{
   // Remove last element
   int last_index = elements.size() - 1;
   int last = elements[last_index];
   elements.pop_back();
   
   if (last_index > 1)
   {
      elements[1] = last;
      fix_heap();     
   }   
}

int Heap::size() const
{
   return elements.size() - 1;
}

void Heap::fix_heap()
{
   int root = elements[1];
   
   int last_index = elements.size() - 1;
   // Promote children of removed root while they are larger than last      
   
   int index = 1;
   bool more = true;
   while (more)
   {
      int child_index = get_left_child_index(index);
      if (child_index <= last_index)
      {
         // Get larger child 
         
         // Get left child first
         int child = get_left_child(index);
         
         // Use right child instead if it is larger
         if (get_right_child_index(index) <= last_index 
            && get_right_child(index) > child)
         {
            child_index = get_right_child_index(index);
            child = get_right_child(index);
         }
         
         // Check if smaller child is larger than root
         if (child > root) 
         {
            // Promote child
            elements[index] = child;
            index = child_index;
         }
         else
         {
            // Root is larger than both children
            more = false;
         }
      }
      else 
      {
         // No children
         more = false; 
      }
   }
   
   // Store root element in vacant slot
   elements[index] = root;
}

int Heap::get_left_child_index(int index)
{
   return 2 * index;
}

int Heap::get_right_child_index(int index)
{
   return 2 * index + 1;
}

int Heap::get_parent_index(int index)
{
   return index / 2;
}

int Heap::get_left_child(int index)
{
   return elements[2 * index];
}

int Heap::get_right_child(int index)
{
   return elements[2 * index + 1];
}

int Heap::get_parent(int index)
{
   return elements[index / 2];
}

int main()
{
   Heap tasks;
   tasks.push(2);
   tasks.push(3);
   tasks.push(2);
   tasks.push(1);
   tasks.push(4);
   tasks.push(9);
   tasks.push(1);
   tasks.push(5);

   while (tasks.size() > 0)
   {
      int task = tasks.top();
      tasks.pop();
      cout << task << "\n";
   }
   return 0;
}
