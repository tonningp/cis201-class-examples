#include<iostream>


int* address_of(int &v)
{
   return &v;
}

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
    p1.point();
    Point *p2 = new Point(2,2);
    p2->print();
    (*p2).print();
    delete p2;
}

int main()
{

;    int x,y,z;
    int *intPtr;
    int *anotherPtr;

    Point p1(1,1);
    p1.print();

    intPtr = new int;
    *intPtr = 100;
    anotherPtr = intPtr;

    std::cout << address_of(x) << std::endl;
    std::cout << &x << std::endl;
    std::cout << x << std::endl;

    std::cout<< intPtr << std::endl;
    std::cout << *anotherPtr << std::endl;
    *intPtr = 200;
    std::cout << *anotherPtr << std::endl;

    return 0;
}

