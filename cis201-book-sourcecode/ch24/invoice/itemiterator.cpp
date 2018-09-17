#include "itemiterator.h"

ItemIterator::ItemIterator(vector<Item*>& its)
   : items(its)
{
   pos = 0;
}

Item* ItemIterator::get() const
{
   if (pos < items.size()) 
      return items[pos];
   else 
      return NULL;
}

bool ItemIterator::is_done() const
{
   return pos >= items.size();
}

