#include<iostream>
#include<vector>
#include "temperature.h"
#include "date.h"

void print(std::vector<Temperature> t)
{
    for(int i=0;i< t.size();i++)
        std::cout << t[i].to_string() << std::endl;
}

int main()
{
    std::vector<Temperature> temps;

    Temperature t1("DAGGET",60,Date(1,1,2018));
    Temperature t2("VV",62,Date(1,2,2018));

    temps.push_back(t1);
    temps.push_back(t2);

    print(temps);
        
    return 0;
}
