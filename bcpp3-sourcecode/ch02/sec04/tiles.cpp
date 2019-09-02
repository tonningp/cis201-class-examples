#include <iostream>

using namespace std;

int main()
{
   cout << "Total width: ";
   int total_width;
   cin >> total_width;
   cout << "Tile width: ";
   int tile_width;
   cin >> tile_width;

   int number_of_pairs = (total_width - tile_width) / (2 * tile_width);
   int number_of_tiles = 1 + 2 * number_of_pairs;
   double gap = (total_width - number_of_tiles * tile_width) / 2.0;

   cout << "Number of tiles: " << number_of_tiles << endl;
   cout << "Gap at each end: " << gap << endl;
   
   return 0;
}
