#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
   A queen in the eight queens problem.
*/
class Queen
{
public:
   /**
      Constructs a queen at a given position.
      @param r the row 
      @param c the column
   */
   Queen(int r, int c);

   /**
      Checks whether this queen attacks another.
      @param other the other queen
      @return true if this and the other queen are in the same
      row, column, or diagonal
   */
   bool attacks(Queen other) const;

   /**
      Prints this queen.
   */
   void print() const;

private:
   int row;
   int column;   
};

Queen::Queen(int r, int c)
{
   row = r;
   column = c;
}

bool Queen::attacks(Queen other) const
{
   return row == other.row
      || column == other.column
      || abs(row - other.row) == abs(column - other.column);
}

void Queen::print() const
{ 
   cout << "abcdefgh"[column] << row + 1; 
}

const int NQUEENS = 8;

const int ACCEPT = 1;
const int ABANDON = 2;
const int CONTINUE = 3;

/**
   A partial solution to the eight queens puzzle.
*/
class PartialSolution
{
public:
   /**
      Examines a partial solution.
      @return one of ACCEPT, ABANDON, CONTINUE
   */
   int examine() const;
   
   /**
      Yields all extensions of this partial solution.
      @return a vector of partial solutions that extend this solution
   */
   vector<PartialSolution> extend() const;

   /**
      Prints this partial solution.
   */
   void print() const;

private:
   vector<Queen> queens;
};

int PartialSolution::examine() const
{
   for (int i = 0; i < queens.size(); i++)
   {
      for (int j = i + 1; j < queens.size(); j++)
      {
         if (queens[i].attacks(queens[j])) { return ABANDON; }
      }
   }
   if (queens.size() == NQUEENS) { return ACCEPT; }
   else { return CONTINUE; }
}

vector<PartialSolution> PartialSolution::extend() const
{
   vector<PartialSolution> result;
   // The next row to populate
   int row = queens.size();
   // Generate a new solution for each column
   for (int column = 0; column < NQUEENS; column++)
   {
      PartialSolution extended;
      // Copy all queens from this solution
      extended.queens = queens; 
      // Add the new queen
      extended.queens.push_back(Queen(row, column));
      result.push_back(extended);
   }
   return result;
}

void PartialSolution::print() const
{
   for (int i = 0; i < queens.size(); i++)
   {
      if (i > 0) { cout << ", "; }
      queens[i].print();
   }
   cout << endl;
}

/**
   Prints all solutions to the problem that can be extended from 
   a given partial solution.
   @param sol the partial solution
*/
void solve(PartialSolution sol)
{
   int exam = sol.examine();
   if (exam == ACCEPT) 
   { 
      sol.print();
   }
   else if (exam == CONTINUE)
   {
      vector<PartialSolution> extended = sol.extend();
      for (int i = 0; i < extended.size(); i++)
      {
         solve(extended[i]);
      }
   }
}

int main()
{
   PartialSolution initial;
   solve(initial);
   return 0;
}

