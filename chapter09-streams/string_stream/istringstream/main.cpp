#include<iostream>
#include<string>
#include<fstream>
#include<sstream>


int main()
{
//    std::ifstream ifs("data.txt");
//    std::string buffer;
//    std::getline(ifs,buffer);
//
    std::istringstream istring("this is a sentence.\n24.5 26.2 1 2 3");
    std::string sentence;
    std::getline(istring,sentence);
    std::cout << sentence << std::endl;
    double value;
    istring >> value;
    std::cout << value << std::endl;
    istring >> value;
    std::cout << value << std::endl;
    int i;
    istring >> i;
    std::cout << i << std::endl;
    istring >> i;
    std::cout << i << std::endl;
    istring >> i;
    std::cout << i << std::endl;
    return 0; 
}
