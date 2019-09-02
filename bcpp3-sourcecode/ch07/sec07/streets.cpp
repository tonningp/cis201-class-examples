#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct StreetAddress
{
   int house_number;
   string street_name;
};

struct MonthlyTemperatures
{
   string location;
   double values[12];
};

struct Person
{
   string name;
   StreetAddress work_address;
};

// A function receiving a structure

void print_address(StreetAddress address)
{
   cout << address.house_number << " " << address.street_name;
}

// A function returning a structure

StreetAddress make_random_address()
{
   StreetAddress result;
   result.house_number = 100 + rand() % 100;
   result.street_name = "Main Street";
   return result;
}

int main()
{
   StreetAddress white_house;
   // Use dot notation to access members:
   white_house.house_number = 1600;
   white_house.street_name = "Pennsylvania Avenue";
   
   cout << "white_house: ";
   print_address(white_house);
   cout << endl;
   
   StreetAddress destination;
   destination = white_house;
   
   cout << "destination: ";
   print_address(destination);
   cout << endl;

   if (destination.house_number == white_house.house_number
      && destination.street_name == white_house.street_name)
   {
      cout << "The destination is the White House" << endl;
   }
   
   cout << endl << "An array of structures" << endl;
   
   const int ROUTE_LENGTH = 4;
   StreetAddress delivery_route[ROUTE_LENGTH];

   delivery_route[0].house_number = 123;
   delivery_route[0].street_name = "Main Street";
   delivery_route[1].house_number = 201;
   delivery_route[1].street_name = "Main Street";
   delivery_route[2].house_number = 420;
   delivery_route[2].street_name = "First Street";
   delivery_route[3] = make_random_address();

   for (int i = 0; i < ROUTE_LENGTH; i++)
   {
      cout << "delivery_route[" << i << "]: ";
      print_address(delivery_route[i]);
      cout << endl;
   }
   
   cout << endl << "A vector of structures" << endl;

   vector<StreetAddress> tour_destinations;
   tour_destinations.push_back(white_house);
   StreetAddress jefferson_memorial;
   jefferson_memorial.house_number = 900;
   jefferson_memorial.street_name = "Ohio Drive SW";
   tour_destinations.push_back(jefferson_memorial);

   for (int i = 0; i < tour_destinations.size(); i++)
   {
      cout << "tour_destinations[" << i << "]: ";
      print_address(tour_destinations[i]);
      cout << endl;
   }

   cout << endl << "A structure containing an array" << endl;
   MonthlyTemperatures death_valley_noon;
   death_valley_noon.location = "Furnace Creek";   
   death_valley_noon.values[0] = 67;
   death_valley_noon.values[1] = 73;
   death_valley_noon.values[2] = 82;
   death_valley_noon.values[3] = 90;
   death_valley_noon.values[4] = 100;
   death_valley_noon.values[5] = 110;
   death_valley_noon.values[6] = 116; // 116°F = 41°C
   death_valley_noon.values[7] = 115;
   death_valley_noon.values[8] = 106;
   death_valley_noon.values[9] = 93;
   death_valley_noon.values[10] = 77;
   death_valley_noon.values[11] = 65;
   
   cout << "death_valley_noon.location: "
      << death_valley_noon.location << endl;
   cout << "death_valley_noon.values: ";
   for (int i = 0; i < 12; i++)
   {
      cout << death_valley_noon.values[i] << " ";
   }
   cout << endl;
   
   cout << endl << "A structure containing a structure" << endl;
   
   Person theodore;
   theodore.name = "Theodore Roosevelt";
   theodore.work_address = white_house;
   cout << "theodore.work_address.street_name: "
      << theodore.work_address.street_name << endl;
   
   return 0;
}
