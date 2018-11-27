#include<iostream>
#include<cstdlib>
#include<string>
#include<fstream>

int main()
{
    std::ifstream input("data.txt");
    //std::string filename;
    //std::cout << "Enter the filename: ";
    //std::getline(std::cin,filename);
    //input.open(filename.c_str());

    if(input.fail()) // indicates if the failbit is set
    {
       std::cerr << "File cannot be read" << std::endl; 
       exit(1);
    }

        int count = 0;
//        while(1)
//        {
            int number;
            double d_number;
            char c;
            std::string s;
            input >> number;
            input >> d_number;
            input >> c;
            input >> s;

            std::cout << "The integer is: " << number << std::endl;
            std::cout << "The double is: " << d_number << std::endl;
            std::cout << "The character is: " << c << std::endl;
            std::cout << "The string is: " << s << std::endl;

/*
            input.get(c);
            if(input.eof())
                break;
            std::cout << c;
            count++;
*/
//        }
    input.close();
    if( input.is_open())
    {
        std::cout << "file is still open" << std::endl;
    }
    else
    {
        std::cout << "file is closed" << std::endl;
    }

    return 0;
}
