#ifndef BEAN_H
#define BEAN_H

class Bean
{
    int m_day;
    int m_amount;

public:
    Bean(int day,int amount);
    int get_day();
    int get_amount();
    void print();
};

#endif
