#include "product.h"

Product::Product() 
{
   price = 0;
}

Product::Product(string d, double p)
{  
   description = d;
   price = p;
}
   
string Product::get_description() const
{  
   return description;
}

double Product::get_price() const
{
   return price;
}

