#ifndef ITEM_H
#define ITEM_H

#include <string>

using namespace std;

/**
   Describes an item in an invoice.
*/
class Item
{  
public:
   /**
      Gets the unit price of this item.
      @return the unit price
   */
   virtual double get_unit_price() const = 0;

   /**
      Gets the description of this item.
      @return the description
   */
   virtual string get_description() const = 0;

   /**
      Gets the quantity of this item.
      @return the quantity
   */
   virtual int get_quantity() const = 0;

   /**
      Gets the total price of this item.
      @return the total price
   */
   double get_total_price() const;

   virtual ~Item(); 
};

#endif
