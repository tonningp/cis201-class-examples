#ifndef BUNDLE_H
#define BUNDLE_H

#include <vector>
#include "item.h"

/**
   A bundle of items that is again an item.
*/
class Bundle : public Item
{
public:
   /**
      Adds an item to this bundle.
      @param it the item to add
   */
   void add(Item* it);
   virtual double get_unit_price() const;
   virtual string get_description() const;
   virtual int get_quantity() const;  
private:
   vector<Item*> items;
};

#endif
