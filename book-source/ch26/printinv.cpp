#include <iostream>
#include <iomanip>

#include <string>
#include <mysql.h>

#include "sutil.h"

using namespace std;

/**
   Prints a customer with a given customer number.
   @param connection the database connection
   @param custnum the customer number
*/
void print_customer(MYSQL* connection, string custnum)
{
   string query = "SELECT Name, Address, City, State, Zip "
      "FROM Customer WHERE Customer_Number = '" + custnum + "'";
   if (mysql_query(connection, query.c_str()) != 0) 
   {
      cout << "Error: " << mysql_error(connection) << "\n";
      return;
   }
   MYSQL_RES* result = mysql_store_result(connection);
   if (result == NULL) 
   {
      cout << "Error: " << mysql_error(connection) << "\n";
      return;
   }
   int rows = mysql_num_rows(result);
   if (rows == 0) 
   {
      cout << "Customer not found.\n";
      return;
   }

   MYSQL_ROW row = mysql_fetch_row(result);  
   string name = row[0];
   string street = row[1];
   string city = row[2];
   string state = row[3];
   string zip = row[4];
   mysql_free_result(result);

   cout << name << "\n" << street << "\n"
      << city << ", " << state << " " << zip << "\n"; 
}

/**
   Prints all items of an invoice.
   @param connection the database connection
   @param invnum the invoice number
*/
void print_items(MYSQL* connection, string invnum)
{
   string query = "SELECT Item.Quantity, Product.Description, "
      "Product.Unit_Price FROM Item, Product WHERE Item.Invoice_Number = '" 
      + invnum + "'AND Item.Product_Code = Product.Product_Code";
   if (mysql_query(connection, query.c_str()) != 0) 
   {
      cout << "Error: " << mysql_error(connection) << "\n";
      return;
   }
   MYSQL_RES* result = mysql_store_result(connection);
   if (result == NULL) 
   {
      cout << "Error: " << mysql_error(connection) << "\n";
      return;
   }
   int rows = mysql_num_rows(result);

   const int COLUMN_WIDTH = 30;
           
   cout << 
      "\n\nDescription                   Price  Qty  Total\n";

   for (int r = 1; r <= rows; r++)
   {
      MYSQL_ROW row = mysql_fetch_row(result);  
      int quantity = string_to_int(row[0]);
      string description = row[1];
      double price = string_to_double(row[2]);

      cout << description;

      // Pad with spaces to fill column
      
      int pad = COLUMN_WIDTH - description.length();
      for (int i = 1; i <= pad; i++)
         cout << " ";
   
      cout << price
         << "   " << quantity 
         << "   " << price * quantity << "\n";
   }

   mysql_free_result(result);
}

/**
   Gets the amount due on all items of an invoice.
   @param connection the database connection
   @param invnum the invoice number
*/
double get_amount_due(MYSQL* connection, string invnum)
{
   string query = "SELECT SUM(Item.Quantity * Product.Unit_Price) "
      "FROM Item, Product WHERE Item.Invoice_Number = '" 
      + invnum + "' AND Item.Product_Code = Product.Product_Code";
   if (mysql_query(connection, query.c_str()) != 0) 
   {
      cout << "Error: " << mysql_error(connection) << "\n";
      return 0;
   }
   MYSQL_RES* result = mysql_store_result(connection);
   if (result == NULL) 
   {
      cout << "Error: " << mysql_error(connection) << "\n";
      return 0;
   }
   int rows = mysql_num_rows(result);
   if (rows == 0) return 0;
   MYSQL_ROW row = mysql_fetch_row(result);  
   double amount_due = string_to_double(row[0]);
   mysql_free_result(result);
   return amount_due;
}

/**
   Prints an invoice.
   @param connection the database connection
   @param invnum the invoice number
*/
void print_invoice(MYSQL* connection, string invnum)
{
   string query = "SELECT Customer_Number, Payment FROM Invoice "
      "WHERE Invoice_Number = '" + invnum + "'";
   if (mysql_query(connection, query.c_str()) != 0) 
   {
      cout << "Error: " << mysql_error(connection) << "\n";
      return;
   }
   MYSQL_RES* result = mysql_store_result(connection);
   if (result == NULL) 
   {
      cout << "Error: " << mysql_error(connection) << "\n";
      return;
   }
   int rows = mysql_num_rows(result);
   if (rows == 0) 
   {
      cout << "Invoice not found.\n";
      return;
   }

   MYSQL_ROW row = mysql_fetch_row(result);  
   string custnum = row[0];
   double payment = string_to_double(row[1]);
   mysql_free_result(result);

   cout << "                     I N V O I C E\n\n";

   print_customer(connection, custnum);
   print_items(connection, invnum);

   double amount_due = get_amount_due(connection, invnum);

   cout << "\nAMOUNT DUE: $" << amount_due - payment << "\n";
}

int main()
{
   MYSQL* connection = mysql_init(NULL);

   if(mysql_real_connect(connection, NULL, NULL, NULL, 
         "bigcpp", 0, NULL, 0) == NULL)
   {
      cout << "Error: " << mysql_error(connection) << "\n";
      return 1;
   }

   cout << "Enter invoice number: ";
   string invnum;

   getline(cin, invnum);
   print_invoice(connection, invnum);

   mysql_close(connection);
   return 0;
}
