#include <iostream>
#include <string>
#include "tree.h"

using namespace std;

int main()
{
   Tree t1("Anne");
   Tree t2("Peter");
   t1.add_subtree(t2);
   Tree t3("Zara");
   t1.add_subtree(t3);
   Tree t4("Savannah");
   t2.add_subtree(t4);
   cout << "Size: " << t1.size() << endl;
   return 0;
}
