#ifndef ITEMITERATOR_H
#define ITEMITERATOR_H

#include <vector>
#include "item.h"

/**
   An iterator through a collection of items.
*/
class ItemIterator
{
public:
   /**
      Constructs the iterator from a vector.
      @param its a reference to a vector of Item pointers
   */
   ItemIterator(vector<Item*>& its);

   /**
      Gets the current item.
      @return the current item pointer
   */
   Item* get() const;

   /**
      Advances to the next item.
   */
   void next();

   /**
      Tests whether there are more items.
      @return true if no more items are available
   */
   bool is_done() const;
private:
   const vector<Item*>& items;
   int pos;
};

inline void ItemIterator::next()
{
   pos++;
}

#endif
