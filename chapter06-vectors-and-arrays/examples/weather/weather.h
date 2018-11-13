#ifndef WEATHER_H
#define WEATHER_H
#include<string>
#include "date.h"
#include "ccc_time.h"

class Weather
{
    int m_high;
    int m_low;
    double m_precip;
    std::string m_location;
    Time m_time;
    Date m_date;

public:
    Weather();
    Weather(std::string location,int high,int low,double precip,Date date,Time time);
    std::string to_string();
    void read();  

};

#endif
