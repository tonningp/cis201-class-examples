#ifndef POINT_H
#define POINT_H
#include<string>
class Point
{
    double m_x,m_y;
    std::string m_name;
public:
    Point(const std::string &name,double x,double y);
    void print();
    std::string to_string();
};
#endif
