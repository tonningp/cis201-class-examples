#include<iostream>
#include "beanpot.h"

const int MAX_DAY = 7;
void Beanpot::add_bean(const Bean &bean)
{
    m_beans.push_back(bean);
}

std::vector<int> Beanpot::daily_balances()
{
    std::vector<int> balances;
    int sum = 0;
    for(int day=0;day < MAX_DAY; day++)
    {
        sum = sum + get_bean_totals_for_day(day+1);
        balances.push_back(sum);
    }
    return balances;
}

int Beanpot::get_bean_totals_for_day(int day)
{
    int sum = 0;
    for(int i=0;i<m_beans.size();i++)
    {
       if( m_beans[i].get_day()  == day)
            sum += m_beans[i].get_amount();
    }

    return sum;

}

int Beanpot::get_average_balance(const std::vector<int> &balances)
{
    int sum = 0;
    for(int i=0;i<balances.size();i++)
    {
        sum += balances[i];
    }
    return sum/balances.size();
}


void Beanpot::print_transactions_for_day(int day)
{
    for(int i=0;i<m_beans.size();i++)
    {
       if( m_beans[i].get_day()  == day)
            std::cout << m_beans[i].get_day() << '\t' << m_beans[i].get_amount() << std::endl;
    }
}

void Beanpot::print_daily_report()
{
    std::vector<int> balances = daily_balances();
    for(int day=0;day < MAX_DAY;day++)
    {
        print_transactions_for_day(day+1);
        std::cout << "Day " <<  day + 1 <<  " balance = " << balances[day] << std::endl;
    }

    std::cout << "Average daily balance: " << get_average_balance(balances) << std::endl;
}
    
