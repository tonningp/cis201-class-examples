#include<iostream>
#include<sys/unistd.h>
#include<cassert>
#include<string>
#include<cmath>
#include <chrono>
#include <thread>

#include "box.h"


void clear()
{
    system("clear");
}

void sleep(int x)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(x));
}

int main()
{
    int resp;
    int width=3;
    int height=3;
    for(int i=0;i < 100; i++)
    {
        Box(width,height).display();
        sleep(100);
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
