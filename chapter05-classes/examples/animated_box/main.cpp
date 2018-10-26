#include<iostream>
#include<cassert>
#include<string>
#include<cmath>
#include "box.h"


void clear()
{
    system("clear");
}

void sleep()
{
    system("sleep 1");
}

int main()
{
    int resp;
    int width=3;
    int height=3;
    for(int i=0;i < 100; i++)
    {
        Box(width,height).display();
        clear();
        if(width > 24)
          width = 3;
        else
          width++;
        if(height > 24)
          height = 3;
        else
          height++;
    }

    return 0;
}
