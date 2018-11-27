#include<iostream>
#include<cstdlib>
#include<string>
#include<fstream>
/*
 * usage: ./main datafile
 */

int main(int argc,char **argv)
{
    if(argc < 2)
    {
        std::cerr << "usage: " << argv[0] << " datafile" << std::endl;
        exit(1);
    }
    std::ifstream input;
    input.open(argv[1]);
    if( input.is_open())
    {
        int value;
        double total = 0.0;
        int count=0;
        while(input >> value)
        {
            total += value;     
            count++;
        }
        std::cout << "The average is " << (total/count) << std::endl;
    }
    else
    {
        std::cout << "File is not open for reading" << std::endl;
    }

    return 0;
}
