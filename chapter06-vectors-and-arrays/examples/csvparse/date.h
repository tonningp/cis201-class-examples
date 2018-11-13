#ifndef DATE_H
#define DATE_H
#include<string>

class Date
{
   int m_month,m_day,m_year;

public:
    Date();
    Date(int month,int day,int year);
    std::string to_string();
};
#endif
