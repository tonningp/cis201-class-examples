#include<iostream>
#include "weatherlog.h"

void Weatherlog::add(const Weather &w)
{
    m_weather.push_back(w);
}

void Weatherlog::print()
{
    for(int i=0;i< m_weather.size();i++)
        std::cout << m_weather[i].to_string() << std::endl;
}

void Weatherlog::read()
{
    Weather w;
    while(! std::cin.eof())
    {
        w.read();
        m_weather.push_back(w);
   }
}
