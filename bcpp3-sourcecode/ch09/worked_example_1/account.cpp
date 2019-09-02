#include <iostream>
#include <iomanip>

using namespace std;

/**
   A bank account whose balance can be changed by deposits and withdrawals.
*/
class BankAccount
{
public:
   /**
      Constructs a bank account with zero balance.
   */
   BankAccount();

   /**
      Constructs a bank account with a given balance.
      @param initial_balance the initial balance
   */
   BankAccount(double initial_balance);

   /**
      Makes a deposit into this account.
      @param amount the amount of the deposit
   */
   void deposit(double amount);

   /**
      Makes a withdrawal from this account, or charges a penalty if
      sufficient funds are not available.
      @param amount the amount of the withdrawal
   */
   void withdraw(double amount);

   /**
      Adds interest to this account.
      @param rate the interest rate in percent
   */
   void add_interest(double rate);

   /**
      Gets the current balance of this bank account.
      @return the current balance
   */
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
   const double PENALTY = 10;
   if (amount > balance)
   {
      balance = balance - PENALTY;
   }
   else
   {
      balance = balance - amount;
   }
}

void BankAccount::add_interest(double rate)
{
   double amount = balance * rate / 100;
   deposit(amount);
}

double BankAccount::get_balance() const
{
   return balance;
}

int main()
{
   BankAccount harrys_account(1000);
   harrys_account.deposit(500);
   harrys_account.withdraw(2000);
   harrys_account.add_interest(1); 
   cout << fixed << setprecision(2) 
      << harrys_account.get_balance() << endl;

   return 0;
}

