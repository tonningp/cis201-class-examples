#include "picture.h"

int main()
{
   const int MAX_WIDTH = 720;
   const int GAP = 10;
   const int PICTURES = 20;

   Picture pic("a.png");
   
   pic.save("gallery.png");
   return 0;
}
