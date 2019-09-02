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
