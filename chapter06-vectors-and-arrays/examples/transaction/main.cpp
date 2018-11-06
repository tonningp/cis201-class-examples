#include <vector>

// it is assumed that you will create the transaction.h and transaction.cpp files
#include "transaction.h"

// NOTE!!!  put Transactionlog in a separate file 

class Transactionlog
{
    std::vector<Transaction> m_transactions;
    double m_balance;
    double m_min_balance;
    double m_average_balance;

public:
    void add_transaction(const Transaction &t);
    int min_daily_balance();
    int average_daily_balance();
    void print();
};


int main()
{
    Transactionlog tlog;

    tlog.add_transaction(Transaction(15,-255,"Cash Withdraw"));
    
    tlog.print();

    return 0;
}
