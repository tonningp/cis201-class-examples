#include <iostream>
#include <vector>

using namespace std;

class Puzzle
{
public:
   Puzzle(int disks);
   void move_single_disk(int from, int to);
   void move(int ndisks, int from, int to);
   void print() const;
private:
   vector<int> towers[3];
};

Puzzle::Puzzle(int ndisks)
{
   for (int d = ndisks; d >= 1; d--)
   {
      towers[0].push_back(d);
   }
}

void Puzzle::move_single_disk(int from, int to)
{
   int last = towers[from].size() - 1;
   int disk = towers[from][last];
   towers[from].pop_back();
   towers[to].push_back(disk);
}

void Puzzle::move(int disks, int from, int to)
{
   if (disks > 0)
   {
      int other = 3 - from - to;
      move(disks - 1, from, other);
      move_single_disk(from, to);
      print();
      move(disks - 1, other, to);
   }
}

void Puzzle::print() const
{
   for (int i = 0; i < 3; i++)
   {
      if (i > 0) cout << "| ";
      for (int j = 0; j < towers[i].size(); j++)
      {
         cout << towers[i][j] << " ";
      }
   }
   cout << endl;
}
   
int main()
{
   Puzzle hanoi(5);
   hanoi.print();
   hanoi.move(5, 0, 2);
   return 0;
}
