#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

/**
   Describes a product with a description and a price.
*/
class Product
{
public:  
   Product();
   Product(string d, double p);
   
   /**
      Gets the product description.
      @return the description
   */
   string get_description() const;

   /**
      Gets the product price.
      @return the unit price
   */
   double get_price() const;
private: 
   string description;
   double price;
};

Product::Product()
{
   price = 0;
}

Product::Product(string d, double p)
{  
   description = d;
   price = p;
}
   
string Product::get_description() const
{  
   return description;
}

double Product::get_price() const
{
   return price;
}
   
/**
   Describes a quantity of an article to purchase and its price.
*/
class LineItem
{  
public:
   LineItem();
   LineItem(Product p, int q);
   
   /**
      Computes the total cost of this line item.
      @return the total price
   */
   double get_total_price() const;
  
   /**
      Prints this line item.
   */
   void print() const;
private:
   Product prod;
   int quantity;
};

LineItem::LineItem()
{
   quantity = 0;
}

LineItem::LineItem(Product p, int q)
{  
   prod = p;
   quantity = q;
}

double LineItem::get_total_price() const
{  
   return prod.get_price() * quantity;
}
   
void LineItem::print() const
{  
   cout << left << setw(28) 
      << prod.get_description()
      << right << fixed << setprecision(2) 
      << setw(7) << prod.get_price() 
      << setw(5) << quantity 
      << setw(7) << get_total_price() << "\n";
}

/**
   Describes a mailing address.
*/
class Address
{  
public:  
   Address(string n, string s, string c, string st, string z);
   
   /**
      Prints the address.
   */
   void print() const;
private:
   string name;
   string street;
   string city;
   string state;
   string zip;
};

Address::Address() {}

Address::Address(string n, string s, string c, string st, string z)
{  
   name = n;
   street = s;
   city = c;
   state = st;
   zip = z;
}   

void Address::print() const
{  
   cout << name << "\n" << street << "\n"
      << city << ", " << state << " " << zip << "\n"; 
}
   
/**
   Describes an invoice for a set of purchased products.
*/
class Invoice
{
public:
   Invoice(Address a);
   
   /**
      Adds a charge for a product to this invoice.
      @param p the product that the customer ordered
      @param quantity the quantity of the product
   */
   void add(Product p, int quantity);
   
   /**
      Prints the invoice.
   */
   void print() const;
private:
   Address billing_address;
   vector<LineItem> items;
};

Invoice::Invoice(Address a)
{  
   billing_address = a;
}
  
void Invoice::add(Product p, int q)
{  
   LineItem it(p, q);
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

   cout << "\nAMOUNT DUE: $" << amount_due << "\n";
}

int main()
{  
   Address sams_address("Sam's Small Appliances",
         "100 Main Street", "Anytown", "CA", "98765");

   Invoice sams_invoice(sams_address);
   sams_invoice.add(Product("Toaster", 29.95), 3);
   sams_invoice.add(Product("Hair dryer", 24.95), 1);
   sams_invoice.add(Product("Car vacuum", 19.99), 2);

   sams_invoice.print();           
   return 0;
}
