#include <iostream>
#include <stack>
#include "maze.h"

using namespace std;

/*
   This program uses a stack to find a path from a position 
   in a maze to an exit. It is assumed that the maze has no circular
   paths, and that there is at least one exit.
*/
int main()
{
   Maze maze(vector<string> {
      "*****************************",
      "** ***                      *",
      "** *** * ********************",
      "** *** *         *          *",
      "** *** * *******   **** *****",
      "**     * ************** *****",
      "****** ******* *******  *****",
      "******         ******* ******",
      "*      ******* ******* ******",
      "* **** ******* **           *",
      "*    ********* ******* ******",
      "* ****         ***     ******",
      "************** **************"});

   int row = 5;
   int column = 8;
   
   stack<Path> s;
   for (Path p : maze.paths_from(row, column))
   {
      s.push(p);
   }

   while (s.size() > 0)
   {
      Path p = s.top();
      s.pop();
      cout << "Following ";
      p.print();
      int r = p.get_ending_row();
      int c = p.get_ending_column();
      if (maze.is_exit(r, c))
      {
         cout << "Exit!" << endl;
         return 0;
      }
      else if (maze.is_dead_end(r, c))
      {
         cout << "Dead end" << endl;
      }
      else 
      {
         for (Path p2 : maze.paths_from(r, c))
         {
            if (!p2.is_opposite(p))
            {                  
               s.push(p2);
            }
         }
      }
   }
}
