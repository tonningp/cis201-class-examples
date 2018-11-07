#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include<string>
#include "date.h"

class Temperature
{
    int m_temp;
    Date m_date;
    std::string m_location;

public:
    Temperature();
    Temperature(std::string location,int temp,Date date);
    std::string to_string();

};

#endif
