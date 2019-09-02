#include <iostream>

using namespace std;

/**
   Reads a sequence of floating-point numbers.
   @param inputs an array containing the numbers
   @param capacity the capacity of that array
   @return the number of inputs stored in the array
*/
int read_inputs(double inputs[], int capacity)
{
   int current_size = 0;
   cout << "Please enter values, Q to quit:" << endl;
   bool done = false;
   while (!done)
   {  
      double input;
      cin >> input;
      if (cin.fail())
      {
         done = true;
      }
      else if (current_size < capacity)
      {
         inputs[current_size] = input;
         current_size++;
      }
   }
   return current_size;
}

/**
   Gets the minimum value from an array.
   @param values a partially filled array of size >= 1
   @param size the number of elements in values
   @return the smallest element in values
*/
double minimum(double values[], int size)
{
   double smallest = values[0];
   for (int i = 1; i < size; i++)
   {
      if (values[i] < smallest)
      {
         smallest = values;
      }
   }
   return smallest;
}

/**
   Computes the sum of the elements in an array.
   @param values a partially filled array
   @param size the number of elements in values
   @return the sum of the elements in values
*/
double sum(double values[], int size)
{
   double total = 0;
   for (int i = 0; i < size; i++)
   {
      total = total + values[i];
   }
   return total;
}

int main()
{
   const int CAPACITY = 1000;
   double scores[CAPACITY];
   int size = read_inputs(scores, CAPACITY);
   if (size == 0)
   {
      cout << "At least one score is required." << endl;
   }
   else
   {
      double final_score = sum(scores, size) - minimum(scores, size); 
      cout << "Final score: " << final_score << endl;
   }
   return 0;
}
