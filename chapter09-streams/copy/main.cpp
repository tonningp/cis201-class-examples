#include<iostream>
#include<cstdlib>
#include<fstream>

bool is_valid_input(std::ifstream& in,char *filename)
{
    in.open(filename);
    return !in.fail();
}

void check_args(int argc,char **argv) 
{
    // check if there are 3 parameters    
    if(argc != 3)
    {
        std::cerr << "usage: " << argv[0] << " inputfile outputfile"<< std::endl;
        exit(1);
    }
}

int main(int argc,char **argv)
{
    std::cout << sizeof(unsigned short) << std::endl;
    check_args(argc,argv);

    std::ifstream in;
    std::ofstream out;
    if(is_valid_input(in,argv[1]))
    {
        std::cout << "Is valid" << std::endl;
        while(1)
        {
            char c = in.get();
            if(!in.eof())
                std::cout << std::hex << static_cast<unsigned short>(c);
                //std::cout.put(c);
            else
                break;
        }
    }
    else
    {
        std::cerr << argv[1] << " is not a valid input file." << std::endl;
        exit(1);
    }
    return 0;
}
