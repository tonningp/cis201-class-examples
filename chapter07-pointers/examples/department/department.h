#ifndef DEPARTMENT_H
#define DEPARTMENT_H
#include <string>
#include "ccc_empl.h"

/** A department in an organization.
*/
class Department
{
public:
   Department(string n);
   void set_receptionist(Employee* e);
   void set_secretary(Employee* e);
   void print() const;
private:
   std::string name;
   Employee* receptionist;
   Employee* secretary;
};

#endif
