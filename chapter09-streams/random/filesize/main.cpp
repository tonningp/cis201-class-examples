#include<iostream>
#include<fstream>


int main()
{
    std::fstream f("data.txt");
    f.seekg(20,std::ios::beg);
    int value;
    f >> value;
    std::cout << value << std::endl;
    value += 5;
    f.seekp(20,std::ios::beg);
    f << value; 
    f.close();
    return 0;
}

