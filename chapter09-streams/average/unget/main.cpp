#include<iostream>
#include<string>
#include<fstream>

int main()
{
    std::ifstream input;
    std::string filename = "data.txt";

    input.open(filename.c_str());

    if( !input.fail())
    {
        int line = 1;
        while(1)
        {
			char ch;
			input.get(ch);
			if ('0' <= ch && ch <= '9') // It was a digit 
			{
   				input.unget(); // Oops - didn't want to read it 
   				int n;
   				input >> n; // Read integer starting with ch
                std::cout << n << std::endl;
			}
            if(input.eof())
                break;
        }
    }

    return 0;
}
