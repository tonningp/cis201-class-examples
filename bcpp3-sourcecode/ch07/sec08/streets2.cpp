#include <iostream>
#include <string>

using namespace std;

struct StreetAddress
{
   int house_number;
   string street_name;
};

struct Employee
{
   string name;
   StreetAddress* office;
};

void print_address(StreetAddress address)
{
   cout << address.house_number << " " << address.street_name;
}

void print_employee(Employee e)
{
   cout << e.name << " working at ";
   print_address(*e.office);
}

int main()
{
   cout << "A dynamically allocated structure" << endl;
   StreetAddress* address_pointer = new StreetAddress;
   (*address_pointer).house_number = 1600;
   address_pointer->house_number = 1600;
   address_pointer->street_name = "Pennsylvania Avenue";
   print_address(*address_pointer);
   delete address_pointer;
   
   cout << endl << "Two employees in the same office" << endl;
   
   StreetAddress accounting;
   accounting.house_number = 1729;
   accounting.street_name = "Park Avenue";
   Employee harry;
   harry.name = "Smith, Harry";
   harry.office = &accounting;
   Employee sally;
   sally.name = "Lee, Sally";
   sally.office = &accounting;

   cout << "harry: ";
   print_employee(harry);
   cout << endl;
   cout << "sally: ";
   print_employee(sally);
   cout << endl;

   cout << "After accounting office move" << endl;
   accounting.house_number = 1720;
   
   cout << "harry: ";
   print_employee(harry);
   cout << endl;
   cout << "sally: ";
   print_employee(sally);
   cout << endl;
   
   return 0;
}

   
