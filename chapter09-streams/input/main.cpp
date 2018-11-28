#include<iostream>
#include<cstdlib>
#include<string>
#include<fstream>

class Student
{
    std::string m_lastname;
    std::string m_firstname;
    int m_id;

public:
    Student(const std::string &firstname,const std::string &lastname,int id);
    int get_id() const;
    void print() const;
};

Student::Student(const std::string &firstname,const std::string &lastname,int id)
{
    m_firstname = firstname;
    m_lastname = lastname;
    m_id = id;
}

int Student::get_id() const
{
    return m_id;
}
void Student::print() const
{
    std::cout << "Id: " << m_id << std::endl
              << "First Name: " << m_firstname << std::endl
              << "Last Name: " << m_lastname << std::endl
              << std::endl;
}


Student read(std::istream &is)
{
        std::string lastname;
        std::string firstname;
        int id;
        is >> id >> firstname >> lastname;
        return Student(firstname,lastname,id);
}

int main()
{
    std::ifstream input("student.txt");


    if(input.fail()) // indicates if the failbit is set
    {
       std::cerr << "File cannot be read" << std::endl; 
       exit(1);
    }

    int count = 0;
    while(1)
    {
        Student st = read(std::cin);
        if(input.eof() || st.get_id() == 0)
            break;
        st.print();

    }
    input.close();

    return 0;
}
