#include "picture.h"

int main()
{
   Picture pic("queen-mary.png");
   
   for (int x = 0; x < pic.width(); x++)
   {
      for (int y = 0; y < pic.height(); y++)
      {
         int red = pic.red(x, y);
         int green = pic.green(x, y);
         int blue = pic.blue(x, y);
         pic.set(x, y, 255 - red, 255 - green, 255 - blue);
      }
   }
   pic.save("out.png");
   return 0;
}
