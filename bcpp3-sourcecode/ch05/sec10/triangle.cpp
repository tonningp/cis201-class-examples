#include <iostream>

using namespace std;

/**
   Prints a triangle with a given side length
   @param side_length the side length (number of [] along the base)
*/
void print_triangle(int side_length)
{
   if (side_length < 1) { return; }
   print_triangle(side_length - 1);
   for (int i = 0; i < side_length; i++)
   {
      cout << "[]";
   }
   cout << endl;
}

int main()
{
   cout << "Enter the side length: ";
   int input;
   cin >> input;
   print_triangle(input);
   return 0;
}
