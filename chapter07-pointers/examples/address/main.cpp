#include<iostream>



class Point 
{ 
    double m_x,m_y;
public:
    Point(double x,double y);
    void set_x(double x);
    void set_y(double y);
    void print();
};

Point::Point(double x,double y)
{
   m_x = x; 
   m_y = y; 
}

void Point::set_x(double x)
{
   m_x = x; 
}
void Point::set_y(double y)
{
   m_y = y; 
}
void Point::print()
{
    std::cout << "(" << m_x << "," << m_y << ")" << std::endl;
}

void do_something_with_points()
{
    Point p1(1,1);
    Point *p2 = new Point(2,2);
    p2->print();
    (*p2).print();
    delete p2;
}

void not_dangerous_function()
{
    int *a = new int[10];

    delete [] a;
}

int main()
{

    while(true)
    {
        not_dangerous_function();
    }

    return 0; 
} 
