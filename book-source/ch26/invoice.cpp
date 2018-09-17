#include <iostream>
#include <iomanip>

#include "invoice.h"

using namespace std;

Invoice::Invoice(Address a)
{  
   billing_address = a;
   payment = 0;
}
  
void Invoice::add(Product p, int q)
{  
   Item it(p, q);
   items.push_back(it);
}

void Invoice::print() const
{  
   cout << "                     I N V O I C E\n\n";
   billing_address.print();
   cout << 
      "\n\nDescription                   Price  Qty  Total\n";
   for (int i = 0; i < items.size(); i++)
      items[i].print();

   double amount_due = 0;
   for (int i = 0; i < items.size(); i++)
      amount_due = amount_due + items[i].get_total_price();

   cout << "\nAMOUNT DUE: $" << amount_due - payment;
}
