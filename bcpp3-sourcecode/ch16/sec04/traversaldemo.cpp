#include <iostream>
#include <string>
#include "tree.h"

using namespace std;

// Count short names with visitor
class Printer : public Visitor
{
public:    
   virtual void visit(string data);
};

void Printer::visit(string data)
{
   cout << data << " ";
}

class ShortNameCounter : public Visitor
{
public:    
   virtual void visit(string data);
   int get() const;
private:   
   int counter = 0;
};

void ShortNameCounter::visit(string data)
{
   if (data.length() <= 5) { counter++; }
}

int ShortNameCounter::get() const
{
   return counter;
}

/*
   This program demonstrates tree traversal.
*/
int main()
{
   Tree t1("Anne");
   Tree t2("Peter");
   t1.add_subtree(t2);
   Tree t3("Zara");
   t1.add_subtree(t3);
   Tree t4("Savannah");
   t2.add_subtree(t4);

   cout << "Preorder: ";
   Printer v1;
   t1.preorder(v1);
   cout << endl;
   ShortNameCounter v2;
   t1.preorder(v2);
   cout << "Short names: " << v2.get() << endl;
   cout << "Postorder: ";
   t1.postorder(v1);
   cout << endl;

   // Print and count short names with breadth first iterator
   
   int counter = 0;
   cout << "Breadth first: ";
   for (BreadthFirstIterator iter = t1.begin();
        !iter.equals(t1.end()); iter.next())
   {
      string data = iter.get();
      cout << data << " ";
      if (data.length() <= 5) { counter++; }
   }
   cout << endl;
   cout << "Short names: " << counter << endl;
}
