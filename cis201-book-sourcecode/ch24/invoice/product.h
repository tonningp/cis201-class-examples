#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

using namespace std;

/**
   Describes a product with a description and a price.
*/
class Product
{
public:  
   /**
      Constructs a product with a given description and price. 
      @param d the description
      @param p the price
   */
   Product(string d, double p);

   /**
      Gets the product description.
      @return the description
   */
   string get_description() const;

   /**
      Gets the product price.
      @return the price
   */
   double get_price() const;
private: 
   string description;
   double price;
};

inline string Product::get_description() const
{  
   return description;
}

inline double Product::get_price() const
{
   return price;
}

#endif
