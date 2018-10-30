#include<iostream>
#include "country.h"


Country::Country(std::string name,int population,int area)
{
    m_name = name;
    m_population = population;
    m_area = area;
}

std::string Country::get_name()
{
    return m_name;
}

bool Country::is_greater_population(const Country &c) const
{
    return m_population >= c.m_population;
}

void Country::print()
{
    std::cout << "Name: " << m_name << std::endl;
    std::cout << "Population: " << m_population << std::endl;
    std::cout << "Area: " << m_area << std::endl;
}
