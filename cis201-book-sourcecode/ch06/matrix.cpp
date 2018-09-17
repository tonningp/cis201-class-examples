#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const int POWERS_ROWS = 11;
const int POWERS_COLS = 6;

/**
   Prints a table of numbers.
   @param the table to print
   @param table_rows the number of rows in the table.
*/
void print_table(const double table[][POWERS_COLS], 
   int table_rows)
{  
   const int WIDTH = 10;
   cout << fixed << setprecision(0);
   for (int i = 0; i < table_rows; i++)
   {  
      for (int j = 0; j < POWERS_COLS; j++)
         cout << setw(WIDTH) << table[i][j];
      cout << "\n";
   }
}

int main()
{  
   double powers[POWERS_ROWS][POWERS_COLS];
   for (int i = 0; i < POWERS_ROWS; i++)
      for (int j = 0; j < POWERS_COLS; j++)
         powers[i][j] = pow(i, j);

   print_table(powers, POWERS_ROWS);

   return 0;
}
