#include <iostream>

using namespace std;

/**
   Generates a sequence of die toss values for testing.
   @param values the array to be filled with die toss values
   @param size the size of the values array
*/
void generate_test_values(int values[], int size)
{
   int next = 1;
   for (int i = 0; i < size; i++)
   {
      values[i] = next;
      next++;
      if (next == 6) { next = 1; }
   }
}

/**
   Counts the number of times each value occurs in a sequence of die tosses.
   @param values an array of die toss values. Each element is >= 1 and <= faces.
   @param size the size of the values array
   @param faces the number of faces of the die
   @param counters an array of counters of length faces + 1. counters[j]
   is filled with the count of elements of values that equal j. counters[0] is
   not used.
*/
void count_values(int values[], int size, int faces, int counters[])
{
   for (int i = 1; i <= faces; i++) { counters[i] = 0; }
   for (int j = 0; j < size; j++)
   {
      int value = values[j];
      counters[value]++;
   }
}

/**
   Prints a table of die value counters.
   @param faces the number of faces of the die
   @param counters an array of counters of length faces + 1.
   counters[0] is not printed.
*/
void print_counters(int faces, int counters[])
{
   for (int i = 1; i <= faces; i++)
   {
      cout << j << ": " << counters[j] << endl;
   }
}

int main()
{
   const int FACES = 6;
   int counters[FACES + 1];
   const int NUMBER_OF_TOSSES = 12;
   int tosses[NUMBER_OF_TOSSES];

   generate_test_values(tosses, NUMBER_OF_TOSSES);   
   count_values(tosses, NUMBER_OF_TOSSES, FACES, counters);
   print_counters(FACES, counters);
   return 0;
}
