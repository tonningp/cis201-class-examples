#include <iostream>

using namespace std;

const int NORTH = 0;
const int EAST = 1;
const int SOUTH = 2;
const int WEST = 3;
const int DIRECTIONS = 4;

class Bug
{
public:
   void move_one_unit();
   void turn_right();
   int get_row() const;
   int get_column() const;
                         
private:
   int row;
   int column;
   int direction; // 0 = North, 1 = East, 2 = South, 3 = West
};

void Bug::move_one_unit()
{   
   if (direction == NORTH) { row--; }
   else if (direction == EAST) { column++; }
   else if (direction == SOUTH) { row++; }
   else if (direction == WEST) { column--; }
}

void Bug::turn_right() 
{
   direction++;
   if (direction == DIRECTIONS) { direction = 0; }
}

int Bug::get_row() const { return row; }
int Bug::get_column() const { return column; }
