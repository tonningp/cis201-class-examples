#include<iostream>
#include<vector>
#include "weather.h"
#include "weatherlog.h"
#include "date.h"
#include "ccc_time.h"


int main()
{
    Weatherlog wl;
    wl.read();
    //wl.add(Weather("DAGGET",60,34,0.00,Date(1,1,2018),Time(23,59,0)));
    //wl.add(Weather("DAGGET",60,34,0.01,Date(1,2,2018),Time(23,59,0)));
    wl.print();

    return 0;
}
