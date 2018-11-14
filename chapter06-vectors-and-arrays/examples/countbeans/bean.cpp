#include<iostream>
#include "bean.h"
Bean::Bean(int day,int amount)
{
    m_day = day;
    m_amount = amount;
}
int Bean::get_day()
{
    return m_day;
}
int Bean::get_amount()
{
    return m_amount;
}
void Bean::print()
{
    std::cout << "Beans for day " << m_day << " are " << m_amount << std::endl;
}
