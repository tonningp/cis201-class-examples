#ifndef WEATHERLOG_H
#define WEATHERLOG_H
#include<vector>
#include "weather.h"


class Weatherlog
{
   std::vector<Weather> m_weather;

public:
   void add(const Weather &w);
   void read();
   void print();
};

#endif
