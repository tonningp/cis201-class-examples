#include<iostream>
#include<cassert>
#include<string>

#include "box.h"

using namespace std;


// constructor with parameters
Box::Box(int width,int height)
{
    set_width(width);
    set_height(height);
}

// mutating function
void Box::set_width(int width)
{
    assert(width > 0);
    m_width = width;
}

// mutating function
void Box::set_height(int height)
{
    assert(height > 0);
    m_height = height;
}

// accessor function
int Box::get_width()
{
    return m_width;
}

// accessor function
int Box::get_height()
{
    return m_height;
}

// display
/**

Box(6,6).display();

╔═════╗
║     ║
║     ║
║     ║
║     ║ 
║     ║
╚═════╝
*/
void Box::display()
{
//    cout << "Box(" << m_width << ","<< m_height << ")" << endl;
    draw_line("╔","═","╗");
    for(int i=0;i<m_height-1;i++) 
        draw_line("║"," ","║");
    draw_line("╚","═","╝");
}

void Box::draw_line(string begin,string mid,string end)
{
    cout << begin;
    for(int i=0;i<m_width-1;i++)
        cout << mid;
    cout << end << endl;
}


