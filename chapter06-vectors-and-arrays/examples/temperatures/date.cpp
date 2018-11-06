#include "date.h"

Date::Date()
{
    m_month = 0;
    m_day = 0;
    m_year = 0;
}

Date::Date(int month,int day,int year)
{
    m_month = month;
    m_day = day;
    m_year = year;
}
