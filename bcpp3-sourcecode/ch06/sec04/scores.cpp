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
   Gets the position of the minimum value from an array.
   @param values a partially filled array of size >= 1
   @param size the number of elements in values
   @return the position of the smallest element in values
*/
int min_position(double values[], int size)
{
   int smallest_position = 0;
   for (int i = 1; i < size; i++)
   {
      if (values[i] < values[smallest_position])
      {
         smallest_position = i;
      }
   }
   return smallest_position;
}

/**
   Removes an element from an array. The order of the elements is not
   preserved.
   @param values a partially filled array
   @param current_size the number of elements in values 
   (will be reduced by 1 if the position is valid)
   @param pos the position of the element to be removed 
*/
void remove(double values[], int& current_size, int pos)
{
   if (0 <= pos && pos < current_size)
   {
      values[pos] = values[current_size - 1];
      current_size--;
   }
}

/**
   Computes the sum of the elements in an array.
   @param values a partially filled array
   @param size the number of elements in values
   @return the sum of the values in values
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

/**
   Removes the smallest value of an array and returns the 
   sum of the remaining values.
   @param values a partially filled array of size >= 1
   @param current_size the number of elements in values (will be reduced by 1)
   @return the sum of the values, excluding the minimum
*/
double final_score(double values[], int& current_size)
{
   int pos = min_position(values, current_size);
   remove(values, current_size, pos);
   return sum(values, current_size);
}

int main()
{
   const int CAPACITY = 1000;
   double scores[CAPACITY];
   int current_size = read_inputs(scores, CAPACITY);
   if (current_size == 0)
   {
      cout << "At least one score is required." << endl;
   }
   else
   {
      double score = final_score(scores, current_size);
      cout << "Final score: " << score << endl;
   }
   return 0;
}
