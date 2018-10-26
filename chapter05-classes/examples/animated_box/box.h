#ifndef BOX_H
#define BOX_H

#include <iostream>
#include <cassert>
#include <string>

using namespace std;

class Box
{

public:
    Box(int width,int height); // constructor with parameters
    void set_width(int width);
    void set_height(int height);
    int get_width();
    int get_height();
    void display();
    void drawline(string corner,string mid);

private:
    int m_width,m_height;
    string m_fill;
};
#endif

