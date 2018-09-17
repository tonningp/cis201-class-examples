#ifndef ITEM_H
#define ITEM_H

#include "product.h"

/**
   Describes a product to purchase and its quantity.
*/
class Item
{
public:  
   /*
      Constructs an item from the product and quantity
      @param p the product
      @param q the item quantity
   */
   Item(Product p, int q);
   
   /**
      Gets the product of this item.
      @return the product
   */
   Product get_product() const;

   /**
      Gets the quantity of this item.
      @return the quantity
   */
   int get_quantity() const;

   /*
      Computes the total cost of this item.
      @return the total price
   */
   double get_total_price() const;

   /*
      prints this item.
   */
   void print() const;

private:
   int quantity;
   Product prod;
};

#endif
