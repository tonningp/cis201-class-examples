#include<iostream>
#include<string>
#include<fstream>

int main()
{
    std::ifstream input;
    std::string filename;
    std::cout << "Enter the filename: ";
    std::getline(std::cin,filename);
    input.open(filename.c_str());
    if( input.is_open())
    {
        int count = 0;
        while(1)
        {
            char c;
            int number;

            input.get(c);
            if(input.eof())
                break;
            std::cout << c;
            count++;
        }
    }
    else
    {
        std::cout << "File is not open for reading" << std::endl;
    }

    return 0;
}
