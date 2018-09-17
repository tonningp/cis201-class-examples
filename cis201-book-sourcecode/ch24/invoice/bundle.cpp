#include "bundle.h"

void Bundle::add(Item* it)
{
   items.push_back(it);
}

double Bundle::get_unit_price() const
{
   double price = 0;
   for (int i = 0; i < items.size(); i++)
   {
      price = price 
         + items[i]->get_unit_price() * items[i]->get_quantity();
   }
   return price;
}

string Bundle::get_description() const
{
   string description = "";
   for (int i = 0; i < items.size(); i++)
   {
      if (i > 0) description = description + ", ";
      description = description + items[i]->get_description();
   }
   return description;
}

int Bundle::get_quantity() const
{
   return 1;
}


