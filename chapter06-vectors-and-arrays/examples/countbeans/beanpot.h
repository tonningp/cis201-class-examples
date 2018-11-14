#ifndef BEANPOT_H
#define BEANPOT_H
#include <vector>
#include "bean.h"

class Beanpot
{
   std::vector<Bean> m_beans;

public:
   void add_bean(const Bean &b);
   std::vector<int> daily_balances();
   int get_bean_totals_for_day(int day);
   void print_daily_report();
   void print_transactions_for_day(int day);
   int get_average_balance(const std::vector<int> &balances);
};

#endif
