#include<iostream>
#include<cassert>

#include "country.h"

Country read();

int main()
{
   Country next = read();
   if(next.is_greater_population(Country("Some Country",10000,100)))
        std::cout << next.get_name() << " has a larger pop than Some Country" << std::endl;
   else
        std::cout << "Some Country has a larger pop than " << next.get_name() << std::endl;

   return 0;
}

Country read()
{
    std::string name;
    int population,area;
    std::cout << "Enter name: ";
    std::getline(std::cin,name);
    std::cout << "Enter population: ";
    std::cin >> population;
    std::cout << "Enter area: ";
    std::cin >> area;
    return Country(name,population,area);
}


