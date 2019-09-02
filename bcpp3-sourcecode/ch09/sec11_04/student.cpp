#include <string>

using namespace std;

class Student
{
public:
   Student(int an_id);
   string get_id() const;
   // No set_id member function
   string get_name() const;
   void set_name(string new_name);
private:
   string name;
   int id;
};

Student::Student(int an_id) { id = an_id; }

string Student::get_id() const { return id; }

string Student::get_name() const { return name; }

void Student::set_name(string new_name)
{
   if (new_name.length() > 0) { name = new_name; }
}

