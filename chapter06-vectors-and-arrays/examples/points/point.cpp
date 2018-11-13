#include<iostream>
#include "point.h"
Point::Point(const std::string &name,double x,double y)
{
    m_x = x;
    m_y = y;
    m_name = name;
}

std::string Point::to_string()
{
    return m_name + " - (" + std::to_string(m_x) + "," + std::to_string(m_y) + ")";
}

void Point::print()
{
    std::cout << to_string() << std::endl;
}
