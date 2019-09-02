#ifndef PATH_H
#define PATH_H

#include <string>

using namespace std;

const int NORTH = 0;
const int EAST = 1;
const int SOUTH = 2;
const int WEST = 3;

/**
   A path in a maze is defined by a starting (row, column) 
   position and a direction (NORTH, EAST, SOUTH, or WEST).
   A path starts out with the same starting and ending position
   and direction. It can be extended as the maze is traversed,
   until it reaches an exit, intersection, or dead end. 

   Intuitively, think of the path as starting at an intersection
   and then moving forward, potentially turning along the 
   way, until it reaches another intersection. 
*/
class Path
{
public:  
   /**
      Constructs a path with a given position and direction.
      @param row the starting row
      @param column the starting column
      @param direction the starting direction
   */
   Path(int row, int column, int direction);

   /**
      Moves the ending position of this path one unit in the
      current direction.
   */
   void move();

   /**
      Turns the ending direction of this path clockwise.
   */
   void turn();

   /**
      Gets the ending row of this path.
      @return the ending row
   */
   int get_ending_row() const;

   /**
      Gets the ending column of this path.
      @return the ending column
   */
   int get_ending_column() const;

   /**
      Gets the next row of this path if it continues in the ending
      direction.
      @return the next row
   */
   int get_next_row() const;

   /**
      Gets the next column of this path if it continues in the ending
      direction.
      @return the next row
   */
   int get_next_column() const;
   
   /**
      Checks whether this path is the opposite of another one.
      @param other another path that ends where this path starts
      @return true if other is the opposite of this path
   */
   bool is_opposite(const Path& other) const;

   /**
      Prints a string representation of this path.
   */
   void print() const;

 private:
   int starting_row;
   int starting_column;
   int starting_direction;
   int ending_row;
   int ending_column;
   int ending_direction;
};

#endif
