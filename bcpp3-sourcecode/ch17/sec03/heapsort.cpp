#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

/**
   Returns the index of the left child.
   @param index the index of a node in this heap
   @return the index of the left child of the given node
*/
int get_left_child_index(int index)
{
   return 2 * index + 1;
}

/**
   Returns the index of the right child.
   @param index the index of a node in this heap
   @return the index of the right child of the given node
*/
int get_right_child_index(int index)
{
   return 2 * index + 2;
}

/**
   Ensures the heap property for a subtree, provided its
   children already fulfill the heap property.
   @param a the array to sort
   @param root_index the index of the subtree to be fixed
   @param last_index the last valid index of the tree that 
   contains the subtree to be fixed
*/
void fix_heap(int a[], int root_index, int last_index)
{
   // Remove root
   int root_value = a[root_index];

   // Promote children while they are larger than the root      

   int index = root_index;
   bool done = false;
   while (!done)
   {
      int child_index = get_left_child_index(index);
      if (child_index <= last_index)
      {
         // Use right child instead if it is larger
         int right_child_index = get_right_child_index(index);
         if (right_child_index <= last_index
            && a[child_index] < a[right_child_index])
         {
            child_index = right_child_index;
         }
         
         if (root_value < a[child_index]) 
         {
            // Promote child
            a[index] = a[child_index];
            index = child_index;
         }
         else
         {
            // Root value is larger than both children
            done = true;
         }
      }
      else 
      {
         // No children
         done = true; 
      }
   }
   
   // Store root value in vacant slot
   a[index] = root_value;
}

/**
   Sorts an array, using heap sort.
   @param a the array to sort
   @param size the number of elements in a
*/
void merge_sort(int a[], int size)
{  
   int n = size - 1;
   for (int i = (n - 1) / 2; i >= 0; i--)
   {
      fix_heap(a, i, n);
   }
   while (n > 0)
   {
      // Swap root with the last element
      int temp = a[0];
      a[0] = a[n];
      a[n] = temp;
      n--;
      fix_heap(a, 0, n);
   }
}

/** 
   Prints all elements in an array.
   @param a the array to print
   @param size the number of elements in a
*/
void print(int a[], int size)
{  
   for (int i = 0; i < size; i++)
   {
      cout << a[i] << " ";
   }
   cout << endl;
}

int main()
{  
   srand(time(0));
   const int SIZE = 20;
   int values[SIZE];
   for (int i = 0; i < SIZE; i++)
   {
      values[i] = rand() % 100;
   }
   print(values, SIZE);
   merge_sort(values, SIZE);
   print(values, SIZE);
   return 0;
}

   

