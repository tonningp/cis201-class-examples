#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

using namespace std;

/**
   Describes a product with a description and a price
*/
class Product
{  
public:

   /**
      Constructs a product with empty description and zero price.
   */
   Product();
   
   /*
      Constructs a product from a description and a price.
      @param d the product description
      @param p the product price
   */
   Product(string d, double p);
   
   /*
      Gets the product description.
      @return the description
   */
   string get_description() const;

   /*
      Gets the product price.
      @return the unit price
   */
   double get_price() const;
   
private:
   string description;
   double price;
};

#endif
