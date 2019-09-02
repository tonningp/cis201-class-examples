#include <iostream>

using namespace std;

/**
   Print instructions for moving a pile of disks from one peg to another.
   @param disks the number of disks to move
   @param from the peg from which to move the disks
   @param to the peg to which to move the disks
*/
void move(int disks, int from, int to)
{
   if (disks > 0) 
   {
      int other = 6 - from - to;
      move(disks - 1, from, other);
      cout << "Move disk from peg " << from << " to " << to << endl;
      move(disks - 1, other, to);
   }
}

int main()
{
   move(5, 1, 3);
   return 0;
}

