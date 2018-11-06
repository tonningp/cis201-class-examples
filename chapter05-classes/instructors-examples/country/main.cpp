#include<iostream>
#include<cassert>

#include "country.h"

Country read_country();

int main()
{
   Country greater_population;
   Country greater_area;
   Country greater_popdensity;
   bool done = false;
   do
   {
       Country next = read_country();

       if(next.is_greater_population(greater_population))
            greater_population = next;
       if(next.is_greater_area(Country(greater_area))
            greater_area = next;
       if(next.is_greater_popdensity(Country(greater_popdensity))
            greater_popdensity = next;
       
       char resp;
       std::cout << "Continue? ";
       cin >> resp;
       if(resp == 'n')
         done = true;

   }while(!done);

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


