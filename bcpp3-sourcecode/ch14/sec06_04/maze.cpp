#include "maze.h"

Maze::Maze(const vector<string>& contents)
{
   cells = contents;
}

vector<Path> Maze::paths_from(int row, int column) const
{
   vector<Path> paths;
   if (is_valid(row - 1, column)) 
   { 
      paths.push_back(Path(row, column, NORTH));
   }
   if (is_valid(row, column + 1))
   { 
      paths.push_back(Path(row, column, EAST));
   }     
   if (is_valid(row + 1, column)) 
   { 
      paths.push_back(Path(row, column, SOUTH));
   }
   if (is_valid(row, column - 1)) 
   { 
      paths.push_back(Path(row, column, WEST));
   }
   for (int i = 0; i < paths.size(); i++) { extend(paths[i]); }
   return paths;
}

void Maze::extend(Path& p) const
{
   bool done = false;
   while (!done)
   {
      p.move();
      int row = p.get_ending_row();
      int column = p.get_ending_column();
      if (is_exit(row, column) || count_neighbors(row, column) != 2)
      {
         done = true; // Either a straight path or a turn
      }
      else
      {
         row = p.get_next_row();
         column = p.get_next_column();
         if (!is_valid(row, column))
         {
            p.turn();
            row = p.get_next_row();
            column = p.get_next_column();
            if (!is_valid(row, column))
            {
               p.turn();
               p.turn();
            }            
         }
      }
   }
}

bool Maze::is_exit(int row, int column) const
{
   return (row == 0 || row == cells.size() - 1 
      || column == 0 || column == cells[row].length() - 1)
      && cells[row][column] == ' ';
}

bool Maze::is_dead_end(int row, int column) const
{
   return count_neighbors(row, column) == 1;
}

bool Maze::is_valid(int row, int column) const
{
   return 0 <= row && row < cells.size() 
      && 0 <= column && column < cells[row].length()
      && cells[row][column] == ' ';
}

int Maze::count_neighbors(int row, int column) const
{
   int count = 0;
   if (is_valid(row - 1, column)) { count++; }
   if (is_valid(row + 1, column)) { count++; }
   if (is_valid(row, column - 1)) { count++; }
   if (is_valid(row, column + 1)) { count++; }
   return count;
}
