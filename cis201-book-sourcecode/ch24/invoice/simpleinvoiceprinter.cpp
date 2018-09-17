#include <iostream>
#include <iomanip>

#include "simpleinvoiceprinter.h"

using namespace std;

SimpleInvoicePrinter::SimpleInvoicePrinter(vector<int> widths)
{
   column_widths = widths;
   column = 0;
}

void SimpleInvoicePrinter::print_header(string s)
{   
   int width = 0;
   for (int i = 0; i < column_widths.size(); i++) 
      width = width + column_widths[i];
   for (int j = 0; j < (width - s.length()) / 2; j++)
      cout << " ";
   cout << s << "\n\n";
}

void SimpleInvoicePrinter::next_column()
{
   column++;
   if (column == column_widths.size())
   {
      cout << "\n";
      column = 0;      
   }
}

void SimpleInvoicePrinter::print_string(string value, bool pad_right)
{
   if (pad_right) cout << value;
   // print padding
   for (int i = value.length(); i < column_widths[column]; i++)
      cout << " ";
   if (!pad_right) cout << value;
   next_column();
}

void SimpleInvoicePrinter::print_number(double value, int precision)
{
   cout << setw(column_widths[column]) 
      << fixed << setprecision(precision) 
      << value;
   next_column();
}

void SimpleInvoicePrinter::print_footer(string s, double total)
{
   cout << "\n" << s << " " << total << "\n";
}


