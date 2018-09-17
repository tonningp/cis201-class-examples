#include <vector>

#include "bundle.h"
#include "invoice.h"
#include "productitem.h"
#include "simpleinvoiceprinter.h"

using namespace std;

int main()
{  
   Invoice sample_invoice;
   vector<int> widths;
   widths.push_back(30);
   widths.push_back(12);
   widths.push_back(4);
   widths.push_back(12);
   SimpleInvoicePrinter printer(widths);
   sample_invoice.add(new ProductItem(Product("Toaster", 29.99), 3));
   Bundle* combo = new Bundle();
   combo->add(new ProductItem(Product("Hammer", 19.95), 1));
   combo->add(new ProductItem(Product("Nails", 0.01), 100));
   sample_invoice.add(combo);

   sample_invoice.print(printer); 
   return 0;
}
