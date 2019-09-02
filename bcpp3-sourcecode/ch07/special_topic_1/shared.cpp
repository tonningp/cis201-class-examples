#include <iostream>
#include <memory>
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
   shared_ptr<StreetAddress> office;
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
   shared_ptr<StreetAddress> accounting(new StreetAddress);
   accounting->house_number = 1729;
   accounting->street_name = "Park Avenue";
   Employee harry;
   harry.name = "Smith, Harry";
   harry.office = accounting;
   Employee sally;
   sally.name = "Lee, Sally";
   sally.office = accounting;

   cout << "harry: ";
   print_employee(harry);
   cout << endl;
   cout << "sally: ";
   print_employee(sally);
   cout << endl;

   cout << "After accounting office move" << endl;
   accounting->house_number = 1720;
   
   cout << "harry: ";
   print_employee(harry);
   cout << endl;
   cout << "sally: ";
   print_employee(sally);
   cout << endl;
   
   return 0;
}
