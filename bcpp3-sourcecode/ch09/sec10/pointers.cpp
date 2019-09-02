#include <iostream>

#include "cashregister.h"
#include "account.h"

using namespace std;

int main()
{
   // A pointer to an object that is allocated on the heap
   CashRegister* register_pointer = new CashRegister;

   // Two pointers to the same object
   BankAccount* lisas_account_pointer = new BankAccount(1000);
   BankAccount* joes_account_pointer = lisas_account_pointer;

   // Invoking a member function on a pointer

   // The hard way
   (*register_pointer).add_item(1.95);

   // The easy way
   register_pointer->add_item(1.95);
   
   cout << "Total sale: " << register_pointer->get_total() << endl;

   // The account balance is the same through either of the
   // pointers to the shared object
   cout << "Lisa's balance: "
      << lisas_account_pointer->get_balance() << endl;
   cout << "Joe's balance: "
      << joes_account_pointer->get_balance() << endl;

   // Deleting the allocated objects
   delete register_pointer;
   delete lisas_account_pointer;
}
