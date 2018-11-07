#include "weather.h"
#include<string>

Weather::Weather()
{
    m_high = 0;
    m_low = 0;
    m_precip = 0.0;
    m_date= Date(1,1,0);
    m_time= Time();
    m_location = "Undefined";
}

Weather::Weather(std::string location,int high,int low,double precip,Date date,Time time)
{
    m_high = high;
    m_low = low;
    m_date= date;
    m_time= time;
    m_precip = precip;
    m_location = location;
}

std::string Weather::to_string()
{
    return m_location 
           + "," + m_date.to_string()
           + "," + std::to_string(m_time.get_hours()) + std::to_string(m_time.get_minutes())
           + "," + std::to_string(m_high)
           + "," + std::to_string(m_low)
           + "," + std::to_string(m_precip);
}
