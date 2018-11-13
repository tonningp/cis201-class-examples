#include <iostream>
#include "department.h"


/**
   Constructs a department with a given name.
   @param n the department name
*/
Department::Department(string n)
{
   name = n;
   receptionist = NULL;
   secretary = NULL;
}

/**
   Sets the receptionist for this department.
   @param e the receptionist
*/
void Department::set_receptionist(Employee* e)
{
   receptionist = e;
}

/**
   Sets the secretary for this department.
   @param e the secretary
*/
void Department::set_secretary(Employee* e)
{
   secretary = e;
}

/**
   Prints a description of this department.
*/
void Department::print() const
{
   std::cout << "Name: " << name << "\n"
        << "Receptionist: ";
   if (receptionist == NULL)
      std::cout << "None";
   else
      std::cout << receptionist->get_name() << " "
           << receptionist->get_salary();
   std::cout << "\nSecretary: ";
   if (secretary == NULL)
      std::cout << "None";
   else if (secretary == receptionist)
      std::cout << "Same";
   else 
      std::cout << secretary->get_name() << " "
           << secretary->get_salary();      
   std::cout << "\n";
}

