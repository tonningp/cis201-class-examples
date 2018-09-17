#ifndef INVOICE_H
#define INVOICE_H

#include <vector>

#include "item.h"
#include "invoiceprinter.h"
#include "itemiterator.h"

using namespace std;

/**
   Describes an invoice that bills for a sequence of items.
*/
class Invoice
{
public:
   /**
      Adds an item to this invoice.
      @param it the item that the customer ordered
   */
   void add(Item* it);

   /**
      Prints the invoice.
   */
   void print(InvoicePrinter& printer);

   /**
      Creates an iterator through the items of this invoice.
      @return the iterator
   */
   ItemIterator create_iterator();
private:
   vector<Item*> items;
};

#endif
