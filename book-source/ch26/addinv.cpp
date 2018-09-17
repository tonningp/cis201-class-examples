#include <iostream>
#include <iomanip>

#include <string>
#include <mysql.h>

using namespace std;

#include "sutil.h"

/**
   Finds a customer with a given customer number.
   @param connection the database connection
   @param custnum the customer number
   @return true if a customer with the given number exists
*/
bool find_customer(MYSQL* connection, string custnum)
{
   string query = "SELECT * FROM Customer WHERE Customer_Number = '" 
      + custnum + "'";
   if (mysql_query(connection, query.c_str()) != 0) 
   {
      cout << "Error: " << mysql_error(connection) << "\n";
      return false;
   }
   MYSQL_RES* result = mysql_store_result(connection);
   if (result == NULL) 
   {
      cout << "Error: " << mysql_error(connection) << "\n";
      return false;
   }
   bool r = mysql_num_rows(result) > 0;
   mysql_free_result(result);
   return r;
}

/**
   Finds a product with a given product code.
   @param connection the database connection
   @param prodcode the product code
   @return true if a product with the given code exists
*/
bool find_product(MYSQL* connection, string prodcode)
{
   string query = "SELECT * FROM Product WHERE Product_Code = '" 
      + prodcode + "'";
   if (mysql_query(connection, query.c_str()) != 0) 
   {
      cout << "Error: " << mysql_error(connection) << "\n";
      return false;
   }
   MYSQL_RES* result = mysql_store_result(connection);
   if (result == NULL) 
   {
      cout << "Error: " << mysql_error(connection) << "\n";
      return false;
   }
   bool r = mysql_num_rows(result) > 0;
   mysql_free_result(result);
   return r;
}

/**
   Adds an invoice to the database.
   @param connection the database connection
   @param custnum the customer number
   @param payment the payment amount
   @return the automatically assigned invoice number
*/  
string add_invoice(MYSQL* connection, string custnum, double payment)
{
   string query = "SELECT MAX(Invoice_Number) FROM Invoice";
   if (mysql_query(connection, query.c_str()) != 0) 
   {
      cout << "Error: " << mysql_error(connection) << "\n";
      return "";
   }
   MYSQL_RES* result = mysql_store_result(connection);
   if (result == NULL) 
   {
      cout << "Error: " << mysql_error(connection) << "\n";
      return "";
   }
   int rows = mysql_num_rows(result);
   if (rows == 0) return "";
   MYSQL_ROW row = mysql_fetch_row(result);  
   int max = string_to_int(row[0]);
   mysql_free_result(result);


   string invnum = int_to_string(max + 1);
   string command = "INSERT INTO Invoice VALUES ('" + invnum + "', '" 
      + custnum + "', " + double_to_string(payment) + ")";
   if (mysql_query(connection, command.c_str()) != 0) 
   {
      cout << "Error: " << mysql_error(connection) << "\n";
      return "";
   }
   return invnum;
}

/**
   Adds an item to the database.
   @param connection the database connection
   @param invnum the invoice number
   @param prodcode the product code
   @param quantity the quantity
*/
void add_item(MYSQL* connection, string invnum, string prodcode, 
   int quantity)
{
   string command = "INSERT INTO Item VALUES ('" + invnum + "', '" 
      + prodcode + "', " + int_to_string(quantity) + ")";
   if (mysql_query(connection, command.c_str()) != 0) 
   {
      cout << "Error: " << mysql_error(connection) << "\n";
      return;
   }
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

   cout << "Enter customer number: ";
   string custnum;
   cin >> custnum;

   if (!find_customer(connection, custnum)) 
   {
      cout << "Customer not found.\n";
      mysql_close(connection);
      return 0;
   }

   cout << "Enter payment: ";
   double payment;
   cin >> payment;

   string invnum = add_invoice(connection, custnum, payment); 
   if (invnum == "")
   {
      mysql_close(connection);
      return 0;      
   }

   bool more = true;
   while (more)
   {
      cout << "Enter product code, - when done: ";
      string prodcode;
      cin >> prodcode;
      if (prodcode == "-") more = false;
      else
      {
         if (find_product(connection, prodcode))
         {
            cout << "Enter quantity: ";
            int quantity;
            cin >> quantity;
            add_item(connection, invnum, prodcode, quantity);
         }
         else cout << "Product not found.\n";
      }
   }
   cout << "Added invoice " << invnum << "\n";
   mysql_close(connection);
   return 0;
}
