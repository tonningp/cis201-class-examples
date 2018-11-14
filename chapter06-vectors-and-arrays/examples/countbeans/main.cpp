#include <iostream>
#include "bean.h"
#include "beanpot.h"


void add_beans(Beanpot &beanpot)
{
    beanpot.add_bean(Bean(1,25));
    beanpot.add_bean(Bean(1,-5));
    beanpot.add_bean(Bean(1,15));
    beanpot.add_bean(Bean(2,10));
    beanpot.add_bean(Bean(2,-15));
    beanpot.add_bean(Bean(2,15));
    beanpot.add_bean(Bean(3,5));
    beanpot.add_bean(Bean(3,15));
    beanpot.add_bean(Bean(3,10));
    beanpot.add_bean(Bean(5,-5));
    beanpot.add_bean(Bean(5,15));
}


int main()
{
    Beanpot beanpot;
    add_beans(beanpot);

    beanpot.print_daily_report();

    return 0;
}


