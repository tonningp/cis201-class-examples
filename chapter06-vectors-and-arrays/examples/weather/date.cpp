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

std::string Date::to_string()
{
    std::string s_month = std::to_string(m_month);
    std::string s_day = std::to_string(m_day);
    if(m_day < 10)
        s_day = "0" + s_day;
    if(m_month < 10)
        s_month = "0" + s_month;
        
    return std::to_string(m_year) + s_month + s_day;
}
