#ifndef PRODUCTITEM_H
#define PRODUCTITEM_H

#include "product.h"
#include "item.h"

/**
   An item that results from selling a quantity of a product.
*/
class ProductItem : public Item
{  
public:
   /**
      Constructs this item.
      @param p the product that is being sold
      @param q the quantity
   */
   ProductItem(const Product& p, int q);
   virtual double get_unit_price() const;
   virtual string get_description() const;
   virtual int get_quantity() const;
private:
   Product prod;
   int quantity;
};

inline int ProductItem::get_quantity() const
{
   return quantity;
}

#endif
