#ifndef SIMPLEINVOICEPRINTER_H
#define SIMPLEINVOICEPRINTER_H

#include <string>
#include <vector>

using namespace std;

#include "invoiceprinter.h"

/**
   Prints an invoice in a monospaced font, using spaces to 
   align the columns.
*/
class SimpleInvoicePrinter : public InvoicePrinter
{
public:
   /**
      Constructs a simple invoice printer and sets the column widths.
      @param widths an array of column widths
   */
   SimpleInvoicePrinter(vector<int> widths);
   virtual void print_header(string s);
   virtual void print_string(string value, bool pad_right);
   virtual void print_number(double value, int precision);
   virtual void print_footer(string s, double total);
private:
   void next_column();
   int column;
   vector<int> column_widths;
};

#endif
