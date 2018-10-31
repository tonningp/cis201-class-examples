#include "box.h"

Box::Box(int width,int height)
{
    set_width(width);
    set_height(height);
    m_fill = "  ";
}

void Box::set_width(int width)
{
    assert(width > 0);
    m_width = width;
}

void Box::set_height(int height)
{
    assert(height > 0);
    m_height = height;
}

int Box::get_width()
{
    return m_width;
}

int Box::get_height()
{
    return m_height;
}

void Box::display()
{
    drawline("+","--");
    for(int row=0;row < m_height -1;row++)
    {
        drawline("|",m_fill);
    }
    drawline("+","--");
}

void Box::drawline(string corner,string mid)
{
    cout << corner;
    for(int i=0;i < m_width-1;i++)
        cout << mid;
    cout << corner  << endl;
}
