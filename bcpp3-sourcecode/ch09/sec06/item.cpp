#include <iostream>

using namespace std;

class Item
{
public:
   Item();
   Item(string a_description);
   Item(string a_description, double a_price);
   void print() const;
private:
   string description; // Constructed with string::string()
   double price = 0; // Data member with initializer; a C++ 11 feature
};

Item::Item()
{
   // All data members initialized with their defaults
}

Item::Item(string a_description)
{
   description = a_description;
   // price initialized with its default
}

Item::Item(string a_description, double a_price)
{
   description = a_description;
   price = a_price;
}

void Item::print() const
{
   cout << "Description: " << description << endl
      << "Price: " << price << endl;
}

int main()
{
   Item default_item;   
   default_item.print();
   Item free_item("Chocolate sample");
   free_item.print();
   Item dessert("Coffee chip ice cream", 4.95);
   dessert.print();
   return 0;
}
