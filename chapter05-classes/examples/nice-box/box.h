#ifndef BOX_H
#define BOX_H
/**
class Box
*/
using namespace std;
class Box
{
    int m_width,m_height;

public:
    Box(int width,int height); // constructor with parameters
    void set_width(int width); // mutating function
    void set_height(int height); // mutating function
    int get_width(); // accessor function
    int get_height(); // accessor function
    void display();   // display
    void draw_line(string begin,string mid,string end);


};
#endif
