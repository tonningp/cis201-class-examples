/**

Description: Dynamic memory example using Department and Employee classes

*/

#include "ccc_empl.h"
#include "department.h"

int main()
{
   Department shipping("Shipping");
   Department qc("Quality Control");
   Employee* harry = new Employee("Hacker, Harry", 45000);
   shipping.set_secretary(harry);
   Employee* tina = new Employee("Tester, Tina", 50000);
   qc.set_receptionist(tina);
   qc.set_secretary(tina);
   tina->set_salary(55000);
   shipping.print();
   qc.print();
   delete tina;
   delete harry;
   return 0;
}
