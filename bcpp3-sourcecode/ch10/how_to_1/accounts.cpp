#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

class BankAccount
{
public:
   /**
      Constructs a bank account with zero balance.
   */
   BankAccount();

   /**
      Makes a deposit into this account.
      @param amount the amount of the deposit.
   */
   virtual void deposit(double amount);

   /**
      Makes a withdrawal from this account, or charges a penalty if
      sufficient funds are not available.
      @param amount the amount of the withdrawal.
   */
   virtual void withdraw(double amount);

   /**
      Carries out the end of month processing that is appropriate
      for this account.
    */
   virtual void month_end();      

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

void BankAccount::deposit(double amount)
{
   balance = balance + amount;
}

void BankAccount::withdraw(double amount)
{
   balance = balance - amount;
}

void BankAccount::month_end() 
{
}

double BankAccount::get_balance() const
{
   return balance;
}

//....................................................................

class SavingsAccount : public BankAccount
{
public:
   /**
      Constructs a savings account with a zero balance
   */
   SavingsAccount();

   /**
      Sets the interest rate for this account.
      @param rate the monthly interest rate in percent
   */
   void set_interest_rate(double rate);
   virtual void withdraw(double amount);
   virtual void month_end();      
private:
   double interest_rate;
   double min_balance;
};

SavingsAccount::SavingsAccount()
{
   interest_rate = 0;
   min_balance = 0;
}

void SavingsAccount::set_interest_rate(double rate)
{
   interest_rate = rate;
}

void SavingsAccount::withdraw(double amount)
{
   BankAccount::withdraw(amount);
   double balance = get_balance();
   if (balance < min_balance)
   {
      min_balance = balance;
   }
}

void SavingsAccount::month_end() 
{
   double interest = min_balance * interest_rate / 100;
   deposit(interest);
   min_balance = get_balance();
}

//....................................................................

class CheckingAccount : public BankAccount
{
public:
   /**
      Constructs a checking account with a zero balance.
   */
   CheckingAccount();
   virtual void withdraw(double amount);
   virtual void month_end();      
private:
   int withdrawals;
};

CheckingAccount::CheckingAccount()
{
   withdrawals = 0;
}

void CheckingAccount::withdraw(double amount)
{
   const int FREE_WITHDRAWALS = 3;
   const int WITHDRAWAL_FEE = 1;

   BankAccount::withdraw(amount);  
   withdrawals++;
   if (withdrawals > FREE_WITHDRAWALS)
   {
      BankAccount::withdraw(WITHDRAWAL_FEE);  
   }
}

void CheckingAccount::month_end() 
{
   withdrawals = 0;
}

//....................................................................

int main()
{
   cout << fixed << setprecision(2);

   // Create accounts
   const int ACCOUNTS_SIZE = 10;
   BankAccount* accounts[ACCOUNTS_SIZE];
   for (int i = 0; i < ACCOUNTS_SIZE / 2; i++)
   {      
      accounts[i] = new CheckingAccount;
   }
   for (int i = ACCOUNTS_SIZE / 2; i < ACCOUNTS_SIZE; i++)
   {      
      SavingsAccount* account = new SavingsAccount;
      account->set_interest_rate(0.75);
      accounts[i] = account;
   }

   // Execute commands
   bool more = true;
   while (more)
   {
      cout << "D)eposit  W)ithdraw  M)onth end  Q)uit: "; 
      string input;
      cin >> input;
      if (input == "D" || input == "W") // Deposit or withdrawal
      {
         cout << "Enter account number and amount: ";
         int num;
         double amount;
         cin >> num >> amount;

         if (input == "D") { accounts[num]->deposit(amount); }
         else { accounts[num]->withdraw(amount); }

         cout << "Balance: " << accounts[num]->get_balance() << endl;
      }
      else if (input == "M") // Month end processing
      {
         for (int n = 0; n < ACCOUNTS_SIZE; n++)
         {
            accounts[n]->month_end();
            cout << n << " " << accounts[n]->get_balance() << endl;
         }
      }
      else if (input == "Q")
      {
         more = false;
      }
   }

   return 0;
}





