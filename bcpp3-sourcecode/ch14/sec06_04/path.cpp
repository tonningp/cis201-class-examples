#include "path.h"
#include <string>

using namespace std;

int ROW_OFFSETS[] = { -1, 0, 1, 0 };
int COLUMN_OFFSETS[] = { 0, 1, 0, -1 };
Path::Path(int row, int column, int direction)
{
   starting_row = row;
   starting_column = column;
   starting_direction = direction;
   ending_row = row;
   ending_column = column;
   ending_direction = direction;
}

void Path::move()
{
   ending_row = get_next_row();
   ending_column = get_next_column();
}

void Path::turn()
{
   const int DIRECTIONS = 4;
   ending_direction = (ending_direction + 1) % DIRECTIONS;  
}

int Path::get_ending_row() const
{
   return ending_row;
}

int Path::get_ending_column() const
{
   return ending_column;
}

int Path::get_next_row() const
{
   return ending_row + ROW_OFFSETS[ending_direction];
}

int Path::get_next_column() const
{
   return ending_column + COLUMN_OFFSETS[ending_direction];
}

/**
   Checks whether two directions are opposites of each other.
   @param dir1 a direction between 0 and 3
   @param dir2 a direction between 0 and 3
   @return true if they are opposites (i.e. 0 and 2, 1 and 3,
   2 and 0, or 3 and 1)
*/
bool opposite(int dir1, int dir2)
{
   return dir1 != dir2 && (dir1 + dir2) % 2 == 0;
}

bool Path::is_opposite(const Path& other) const
{
   return starting_row == other.ending_row
      && starting_column == other.ending_column
      && opposite(starting_direction, other.ending_direction);
}
   
void Path::print() const
{
   string directions = "NESW";
   cout << "(" << to_string(starting_row) << ","
      << to_string(starting_column)
      << ")" << directions.substr(starting_direction, 1);
   if (ending_row != starting_row || ending_column != starting_column)
   {
      cout << "<->(" << to_string(ending_row) << ","
         << to_string(ending_column)
         << ")" << directions.substr(ending_direction, 1); 
   }
   cout << endl;
}
