#ifndef INVOICEPRINTER_H
#define INVOICEPRINTER_H

#include <string>

using namespace std;

/**
   Formats an invoice.
*/
class InvoicePrinter
{
public:
   /**
      Prints the invoice header.
      @param s the header string
   */
   virtual void print_header(string s) = 0;

   /**
      Prints a string in the next table cell.
      @param value the value to print
      @param pad_right true if the cell is padded on the right
      with spaces
   */
   virtual void print_string(string value, bool pad_right) = 0;

   /**
      Prints a number in the next table cell.
      @param value the value to print
      @param precision the number of digits after the decimal point
   */
   virtual void print_number(double value, int precision) = 0;

   /**
      Prints the invoice footer.
      @param s the footer string
      @param total the total amount due
   */
   virtual void print_footer(string s, double total) = 0;
};

#endif
