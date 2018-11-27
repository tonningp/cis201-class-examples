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
    output.open("data.txt");
    if( !output.fail())
    {
        for(int i=0;i < 20;i++)
        {
            output << get_random(300) << std::endl;
        }
    }
    output.close();

    return 0;
}
