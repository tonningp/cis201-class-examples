#include <iostream>

using namespace std;

/**
   Computes the area of a triangle with a given side length.
   @param side_length the side length of the triangle base
   @return the area
*/
int triangle_area(int side_length)
{
   if (side_length <= 0) { return 0; }
   if (side_length == 1) { return 1; }
   int smaller_side_length = side_length - 1;
   int smaller_area = triangle_area(smaller_side_length);
   return smaller_area + side_length;
}

int main()
{
   cout << "Enter the side length: ";
   int input;
   cin >> input;
   cout << "Area: " << triangle_area(input) << endl;
   return 0;
}

