#ifndef INVOICE_H
#define INVOICE_H

#include <string>
#include <vector>

using namespace std;

#include "item.h"
#include "address.h"

/**
   Describes an invoice for a set of purchased products.
*/
class Invoice
{
public:
   /**
      Constructs an invoice with a given address.
      @param a the billing address
   */
   Invoice(Address a);
   /**
      Adds a charge for a product to this invoice.
      @param aProduct the product that the customer ordered
      @param quantity the quantity of the product
   */
   void add(Product p, int quantity);
   /**
      Sets the payment amount.
      @param p the payment amount
   */
   void set_payment(double p)
   {
      payment = p;
   }
   /**
      Prints the invoice.
   */
   void print() const;
private:
   Address billing_address;
   vector<Item> items;
   double payment;
};

#endif
