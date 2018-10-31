#include<iostream>
#include "ccc_time.h"
#include "message.h"

int main()
{

    Message m("Paul Tonning","John Doe",Time());
    m.append("This is the first line of the message");
    m.append("This is the second line of the message");
    m.append("This is the third line of the message");
    m.print();

    return 0;
}
