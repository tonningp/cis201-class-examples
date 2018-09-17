#include "ccc_win.h"

int ccc_win_main()
{  
   Point top_left(1, 3);
   Point top_right(1, 4);
   Point bottom_left(2, 3);

   Line horizontal(top_left, top_right);
   Line vertical(top_left, bottom_left);

   cwin << horizontal << vertical;

   horizontal.move(1, 0);
   vertical.move(0, 1);

   cwin << horizontal << vertical;

   return 0;
}

