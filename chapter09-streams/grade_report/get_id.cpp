#include<iostream>
#include<string>
#include<fstream>


void process_student(std::string id)
{
    std::ifstream input;
    input.open("CSC1.txt");
    if(!input.fail())
    {
        while(!input.eof())
        {
            std::string student_id;
            std::string grade;
            input >> student_id;
            input >> grade;
            if(input.eof())
              break;
            std::cout << "The id is: " << student_id << std::endl;
            std::cout << "The grade is: " << grade << std::endl;
        }
    }
}

int main()
{
    std::string student_id;
    process_student(student_id);
    return 0;
}
