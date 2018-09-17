#include "productitem.h"

ProductItem::ProductItem(const Product& p, int q) 
   :  prod(p)
{  
   quantity = q;
}

double ProductItem::get_unit_price() const
{  
   return prod.get_price();
}

string ProductItem::get_description() const
{  
   return prod.get_description();
}


