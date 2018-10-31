#include<iostream>
#include<cassert>

#include "country.h"

Country read_country();

int main()
{
   Country next = read_country();
   Country greater_population;
   if(next.is_greater_population(Country("Some Country",10000,100)))
        greater_population = next;

   return 0;
}


Country read_country()
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


