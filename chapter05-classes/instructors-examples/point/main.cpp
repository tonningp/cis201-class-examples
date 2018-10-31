#include<iostream>
#include<string>
#include<cmath>

using namespace std;

class Point
{

public:
    Point(); // default constructor
    Point(double _x,double _y); // constructor with parameters
    double distance(Point p);
    void set_x(double _x); // mutating function
    void set_y(double _y); // mutating function
    double get_x(); // accessor function
    double get_y(); // accessor function
    string to_string(); // string representation
private:
    double x,y;
};

Point::Point()
{
    x = 0.0;
    y = 0.0;
}

Point::Point(double _x,double _y)
{
    x = _x;
    y = _y;
}

void Point::set_x(double _x)
{
    x = _x;
}

void Point::set_y(double _y)
{
    y = _y;
}

double Point::get_x()
{
    return x;
}

double Point::get_y()
{
    return y;
}

double Point::distance(Point p)
{
    return sqrt( pow( x - p.x,2 ) + pow( y - p.y,2 ));
}

string Point::to_string()
{
    string s = "(";
    s += std::to_string(x);
    s += ",";
    s += std::to_string(y);
    s += ")";
    return s;
}

int main()
{
    Point p1(2,1),p2(1,2);

    cout << "The distance is " << p1.distance(p2) << endl;

    return 0;
}
