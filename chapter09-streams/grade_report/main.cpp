#include<iostream>
#include<string>
#include<fstream>


void process_student(std::string id)
{
    std::ifstream classes;
    classes.open("classes.txt");
    while(!classes.eof())
    {
        std::string classname;
        std::getline(classes,classname);
        if(classes.eof())
            break;
        std::ifstream class_file;
        classname += ".txt";
        class_file.open(classname.c_str());
        if(!class_file.fail())
        {
            std::cout << "will open the class file: " << classname << std::endl;
            std::cout << "and will look for the student id: " << id << std::endl;
            std::cout << "it will then get the grade from the line that the " << std::endl;
            std::cout << "id is on, to then use that to build the report. : " << std::endl;
        }
        else
        {
            std::cout << "The file " << classname << " cannot be opened" << std::endl;
        }
    }

}

int main()
{
    std::string student_id;
    process_student(student_id);
    return 0;
}
