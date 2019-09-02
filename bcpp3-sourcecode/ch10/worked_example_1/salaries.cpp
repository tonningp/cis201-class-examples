#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

/**
   An employee with a name and a mechanism for computing weekly pay.
 */
class Employee
{
public:
   /**
      Constructs an employee with an empty name.
   */
   Employee();

   /**
      @param employee_name the name of this employee
   */
   void set_name(string employee_name);

   /**
      @return the name of this employee
   */
   string get_name() const;

   /**
      Computes the pay for one week of work
      @param hours_worked the number of hours worked in the week
      @return the pay for the given number of hours
   */
   virtual double weekly_pay(int hours_worked) const;
private:
   string name;
};

Employee::Employee()
{
}

void Employee::set_name(string employee_name)
{
   name = employee_name;
}

string Employee::get_name() const
{
   return name; 
}

double Employee::weekly_pay(int hours_worked) const
{
   return 0; 
}

//....................................................................

class HourlyEmployee : public Employee
{
public:
   /**
      @param name the name of this employee
      @param wage the hourly wage 
   */
   HourlyEmployee(string name, double wage);
 
   virtual double weekly_pay(int hours_worked) const;
private:
   double hourly_wage;
};

HourlyEmployee::HourlyEmployee(string name, double wage)
{
   set_name(name);
   hourly_wage = wage;
}

double HourlyEmployee::weekly_pay(int hours_worked) const
{
   double pay = hours_worked * hourly_wage;
   if (hours_worked > 40)
   {
      pay = pay + ((hours_worked - 40) * 0.5) * hourly_wage;
   }
   return pay;
}

//....................................................................

class SalariedEmployee : public Employee
{
public:
   /**
      @param name the name of this employee
      @param salary the annual salary
    */
   SalariedEmployee(string name, double salary);

   virtual double weekly_pay(int hours_worked) const;
private:
   double annual_salary;
};

SalariedEmployee::SalariedEmployee(string name, double salary)
{
   set_name(name);
   annual_salary = salary;
}

double SalariedEmployee::weekly_pay(int hours_worked) const
{
   const int WEEKS_PER_YEAR = 52;
   return annual_salary / WEEKS_PER_YEAR;
}

//....................................................................

class Manager : public SalariedEmployee
{
public:
   /**
      @param name the name of this employee
      @param salary the annual salary
      @param bonus the weekly bonus
    */
   Manager(string name, double salary, double bonus);

   virtual double weekly_pay(int hours) const;
private:
   double weekly_bonus;
};

Manager::Manager(string name, double salary, double bonus)
   : SalariedEmployee(name, salary)
{
   weekly_bonus = bonus;
}

double Manager::weekly_pay(int hours) const
{
   return SalariedEmployee::weekly_pay(hours) + weekly_bonus;
}

//....................................................................

int main()
{
   vector<Employee*> staff;
   staff.push_back(new HourlyEmployee("Morgan, Harry", 30));
   staff.push_back(new SalariedEmployee("Lin, Sally", 52000)); 
   staff.push_back(new Manager("Smith, Mary", 104000, 50));
      
   for (int i = 0; i < staff.size(); i++)
   {
      cout << "Hours worked by " << staff[i]->get_name() << ": ";
      int hours;
      cin >> hours;
      cout << "Salary: " << staff[i]->weekly_pay(hours) << endl;
   }

   return 0;
}
