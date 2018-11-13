#include<iostream>
#include "weather.h"

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

/**

This is the header for the data file,
The numbers above indicate the field positions
==> data.csv <==
   0        1      2       3       4        5       6
"Station","Date","Time","Precip","type","Air max","min","obs","Wx","Wind dir","speed","Bulb wet","dry","Soil max","min","Evap","Solar","ETo","RH max","min"
*/
void Weather::read()
{
    std::string str;
    std::getline(std::cin,str);
	std::size_t found = str.find_first_of(",");
    std::size_t last = 0;
    // the following 2 lines are debug statements, they wouldn't be in the final program
    std::cout << "012345678901234567890123456789012345678901234567890" << std::endl;
    std::cout << str << std::endl;
    while (found!=std::string::npos)  // npos is -1, it's kind of like eof http://www.cplusplus.com/reference/string/string/npos/
    {
       // if we are in this loop it's because there was a , in the string

       // this is the delimited word that was found between the ,'s  -- this is a debug statement
       std::cout << "(" << last << "," << (found-1) << ") - " << str.substr(last,found-last) << std::endl;

       last = found+1;
       found=str.find_first_of(",",found+1);
    }
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
