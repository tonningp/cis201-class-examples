#ifndef COUNTRY_H
#define COUNTRY_H
#include<string>

class Country
{
    std::string m_name;
    int m_population,m_area;

public:
   Country();
   Country(std::string name,int population,int area);
   std::string get_name();
   bool is_greater_population(const Country &c) const;

   void print();
};




#endif
