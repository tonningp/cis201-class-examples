#include "picture.h"
#include <string>

using namespace std;

int main()
{
   const int MAX_WIDTH = 720;
   const int GAP = 10;
   const string names = "abcdefghijklmnopqrst";
   const int PICTURES = names.length();

   // Read the first picture
   Picture pic("a.png");

   // x and y are the top left corner of the next picture
   int x = pic.width() + GAP;
   int y = 0;

   // max_y is the largest y encountered so far
   int max_y = pic.height(); 
   for (int i = 1; i < PICTURES; i++)
   {
      // Read the next picture
      Picture pic2(names.substr(i, 1) + ".png");
      if (x + pic2.width() >= MAX_WIDTH) // The picture doesn't fit on the current row
      {
         // Place the picture on the next row
         x = 0;
         y = max_y + GAP;
      }
      pic.add(pic2, x, y);
      // Update x and max_y
      x = x + pic2.width() + GAP;
      if (y + pic2.height() > max_y)
      {
         max_y = y + pic2.height();
      }
   }
   pic.save("gallery.png");
   return 0;
}
