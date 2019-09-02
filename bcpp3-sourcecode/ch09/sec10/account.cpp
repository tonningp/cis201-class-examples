#include "account.h"

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
