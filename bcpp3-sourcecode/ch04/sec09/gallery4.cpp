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
   for (int i = 1; i < PICTURES; i++)
   {
      // Read the next picture
      Picture pic2(names.substr(i, 1) + ".png");
      // Place the picture next to the previous one
      pic.add(pic2, x, 0);
      // Update x
      x = x + pic2.width() + GAP;
   }
  
   pic.save("gallery.png");
   return 0;
}
