#include<iostream>
#include<fstream>


int main()
{
    //std::fstream f("random.dat");
    std::fstream f("data.txt");
    f.seekg(20,std::ios::beg);
    int value;
    f >> value;
    std::cout << value << std::endl;
    f.seekg(30,std::ios::beg);
    double dvalue;
    f >> dvalue;
    std::cout << dvalue << std::endl;
     
    return 0;
}

