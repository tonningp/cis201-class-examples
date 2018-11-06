#include "temperature.h"
#include<string>

Temperature::Temperature()
{
    m_temp = 0;
    m_date= Date(1,1,0);
    m_location = "Undefined";
}

Temperature::Temperature(std::string location,int temp,Date date)
{
    m_temp = temp;
    m_date= date;
    m_location = location;
}

std::string Temperature::to_string()
{
    return m_location + "," + std::to_string(m_temp);
}
