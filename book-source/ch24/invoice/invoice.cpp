#include "invoice.h"
#include "itemiterator.h"
#include "invoiceprinter.h"

void Invoice::add(Item* it)
{  
   items.push_back(it);
}

ItemIterator Invoice::create_iterator()
{  
   return ItemIterator(items);
}

void Invoice::print(InvoicePrinter& printer)
{
   printer.print_header("I N V O I C E");
   printer.print_string("Description", true);
   printer.print_string("Unit Price", false);
   printer.print_string("Qty", false);
   printer.print_string("Total Price", false);

   double amount_due = 0;
   for (ItemIterator iter = create_iterator(); 
        !iter.is_done(); iter.next())
   {
      Item* it = iter.get();
      printer.print_string(it->get_description(), true);
      printer.print_number(it->get_unit_price(), 2);
      printer.print_number(it->get_quantity(), 0);
      printer.print_number(it->get_total_price(), 2);
      amount_due = amount_due + it->get_total_price();
   }

   printer.print_footer("AMOUNT DUE:", amount_due);
}
