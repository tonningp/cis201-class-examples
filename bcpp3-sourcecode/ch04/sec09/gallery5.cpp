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

   // x is the left position of the next picture
   int x = pic.width() + GAP;

   // max_y is the largest y encountered so far
   int max_y = pic.height(); 
   for (int i = 1; i < PICTURES; i++)
   {
      // Read the next picture
      Picture pic2(names.substr(i, 1) + ".png");
      if (x + pic2.width() < MAX_WIDTH) // The picture fits on the current row
      {
         pic.add(pic2, x, 0);
         // Update x and max_y
         x = x + pic2.width() + GAP;
         if (pic2.height() > max_y)
         {
            max_y = pic2.height();
         }
      }
      else
      {
         // Place the picture on the next row
         pic.add(pic2, 0, max_y + GAP);
         pic.save("gallery.png");
         return 0;
      }
   }  
}
