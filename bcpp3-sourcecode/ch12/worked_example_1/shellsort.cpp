#include <vector>

using namespace std;

/**
   Sorts a column, using insertion sort.
   @param a the array to sort
   @param size the size of a
   @param k the index of the first element in the column
   @param c the gap between elements in the column
*/
void insertion_sort(int a[], int size, int k, int c)
{
   for (int i = k + c; i < size; i = i + c)
   {
      int next = a[i];
      // Move all larger elements up
      int j = i;
      while (j >= c && a[j - c] > next)
      {
         a[j] = a[j - c];
         j = j - c;
      }
      // Insert the element
      a[j] = next;
   }
}

/**
   Sorts an array, using Shell sort.
   @param a the array to sort
   @param size the size of a
*/
void shell_sort(int a[], int size)
{  
   // Generate the sequence values
   vector<int> columns;
   int c = 1;
   while (c < size) 
   { 
      columns.push_back(c);
      c = 3 * c + 1;          
   }

   // For each column count, sort all columns
   for (int s = columns.size() - 1; s >= 0; s--)
   {
      c = columns[s];
      for (int k = 0; k < c; k++)
      {
         insertion_sort(a, size, k, c);
      }         
   }
}

