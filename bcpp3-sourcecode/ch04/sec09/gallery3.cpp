#include "picture.h"

int main()
{
   const int MAX_WIDTH = 720;
   const int GAP = 10;
   const int PICTURES = 20;

   Picture pic("a.png");
   Picture pic2("b.png");
   // Place the second picture next to the first
   pic.add(pic2, pic.width() + GAP, 0);
   pic.save("gallery.png");
   return 0;
}
