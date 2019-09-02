#include "animation.h"

#include <iostream>


int main()
{
   Picture pic("dog.png");
   Animation anim("animation.gif`", 200, 50);
   cout << pic.width() << endl;
   for (int i = -pic.width(); i < 200; i++)
   {
      anim.add(pic, i, 0);
      anim.frame();
   }
   anim.close();
}
