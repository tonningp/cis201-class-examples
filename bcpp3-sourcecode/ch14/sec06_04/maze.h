#ifndef MAZE_H
#define MAZE_H

#include <vector>
#include "path.h"

using namespace std;

/**
   A maze has its walls marked by * characters and corridors 
   by spaces. It can classify corridor points as dead ends,
   intersections, or exits, and it can extend paths from 
   one intersection to another. The maze is assumed not to have
   any cycles (i.e., paths returning to their own start.)
*/
class Maze
{
public:
   /**
      Constructs a maze from strings describing its contents.
      @param contents strings consisting of * and spaces
   */
   Maze(const vector<string>& contents);

   /**
      Gets all paths emanating from a position in the maze.
      @param row the row of the position
      @param column the column of the position
      @return all paths emanating from the position
   */
   vector<Path> paths_from(int row, int column) const;

   /**
      Checks whether a position is an exit.
      @param row the row of the position
      @param column the column of the position
      @return true if the position is an exit
   */
   bool is_exit(int row, int column) const;

   /**
      Checks whether a position is a dead end.
      @param row the row of the position
      @param column the column of the position
      @return true if the position is a dead end
   */
   bool is_dead_end(int row, int column) const;

 private:
   /**
      Extends this path to the next exit, intersection, or dead end.
      @param p the path to extend
   */
   void extend(Path& p) const;
   /**
      Checks whether a position is within the maze and not a wall.
      @param row the row of the position
      @param column the column of the position
      @return true if the position is valid
   */
   bool is_valid(int row, int column) const;

   /**
      Counts the neighbors of a position.
      @param row the row of the position
      @param column the column of the position
      @return the number of neighbors in the four compass directions
      that are within the maze and not walls
   */
   int count_neighbors(int row, int column) const;

   vector<string> cells;
};

#endif
