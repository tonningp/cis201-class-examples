#include<iostream>
#include "ccc_time.h"
//#include "message.h"


int main()
{
    //Message m("Paul Tonning","John Doe",Time());
    //m.append("This is the first line of the message");
    Time t;
    std::cout << t.get_hours() << std::endl;

    return 0;
}
