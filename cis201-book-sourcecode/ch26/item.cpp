#include <iostream>

#include "item.h"

Item::Item(Product p, int q)
   : prod(p), quantity(q)
{  
}
   
Product Item::get_product() const
{
   return prod;
}

int Item::get_quantity() const
{
   return quantity;
}

double Item::get_total_price() const
{  
   return prod.get_price() * quantity;
}
   
void Item::print() const
{  
   const int COLUMN_WIDTH = 30;
   string description = prod.get_description();
           
   cout << description;

   // pad with spaces to fill column
      
   int pad = COLUMN_WIDTH - description.length();
   for (int i = 1; i <= pad; i++)
      cout << " ";
   
   cout << prod.get_price()
      << "   " << quantity 
      << "   " << get_total_price() << "\n";
}

