#include <iostream>

using namespace std;

class BankAccount
{
public:
   BankAccount(); // Sets balance to 0
   BankAccount(double initial_balance); // Sets balance to initial_balance
   void deposit(double amount);
   void withdraw(double amount);
   double get_balance() const;
private:
   double balance;
};

BankAccount::BankAccount()
{
   balance = 0;
}

BankAccount::BankAccount(double initial_balance)
{
   balance = initial_balance;   
}

void BankAccount::deposit(double amount)
{
   balance = balance + amount;
}

void BankAccount::withdraw(double amount)
{
   balance = balance - amount;
}

double BankAccount::get_balance() const
{
   return balance;
}

int main()
{
   BankAccount joes_account;
      // Uses default constructor
   BankAccount lisas_account(499.95);
      // Uses BankAccount(double) constructor
   cout << "Joe's account balance: " << joes_account.get_balance() << endl;
   cout << "Lisa's account balance: " << lisas_account.get_balance() << endl;
   return 0;
}

