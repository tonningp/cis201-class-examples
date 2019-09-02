#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int ROWS = 6;
const int COLUMNS = 7;

/**
   Computes the total of a column in a table.
   @param table a table with 7 columns
   @param rows the number of rows of the table
   @param column the column that needs to be totaled
   @return the sum of all elements in the given column
*/
int column_total(int table[][COLUMNS], int rows, int column)
{
   int total = 0; 
   for (int i = 0; i < rows; i++)
   {
      total = total + table[i][column];
   }
   return total;
}

int main()
{
   int data[ROWS][COLUMNS] = 
   { 
      { 106, 107, 111, 133, 221, 767, 1766 },
      { 502, 635, 809, 947, 1402, 3634, 5268 }, 
      { 2, 2, 2, 6, 13, 30, 46 }, 
      { 163, 203, 276, 408, 547, 729, 628 },
      { 2, 7, 26, 82, 172, 307, 392 },
      { 16, 24, 38, 74, 167, 511, 809 }
   };

   string continents[ROWS] = 
      { 
         "Africa", 
         "Asia", 
         "Australia",
         "Europe", 
         "North America", 
         "South America" 
      };

   cout << "                Year 1750 1800 1850 1900 1950 2000 2050"
      << endl;

   // Print data
   for (int i = 0; i < ROWS; i++)
   {      
      // Print the ith row
      cout << setw(20) << continents[i];
      for (int j = 0; j < COLUMNS; j++)
      {
         cout << setw(5) << data[i][j];
      }
      cout << endl; // Start a new line at the end of the row
   }

   // Print column totals
   cout << "               World";
   for (int j = 0; j < COLUMNS; j++) 
   {
      cout << setw(5) << column_total(data, ROWS, j);
   }
   cout << endl;

   return 0;
}
