#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
#include<fstream>

int get_random(int scale)
{
    return rand() % scale + 1;
}

int main()
{
    srand(time(0));
    std::ofstream output;
//    output.open("data.txt",std::ios::app);
    //std::cout << output.good() << std::endl;

    output.open("data.txt");

    if( !output.fail())
    {
        for(int i=0;i < 20;i++)
        {
            output << get_random(300) << std::endl;
        }
    }
    else
    {
        std::cout << "File cannot be written" << std::endl;
        exit(1);
    }
    if(output.is_open())
    {
        std::cout << "file is still open" << std::endl;
    }
    output.close();
    if(!output.is_open())
    {
        std::cout << "file is closed" << std::endl;
    }

    return 0;
}
