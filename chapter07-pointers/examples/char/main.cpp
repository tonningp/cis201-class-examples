#include<iostream>
#include<cstring>
#include<string>



int length(char *s)
{
    int count=0;
    while(s[count] != '\0')
        count++;
    return count;
}

void char_copy(char src[],char dest[])
{
    for(int i=0;i <= length(src);i++)
    {
        dest[i] = src[i];
    }
}

const unsigned int SIZE = 512;

int main()
{

    std::string s = "Hello"; 
    char sc[] = {'H','e','l','l','o','\0'};
    char *sc2;

    strcpy(sc2,sc); 

    std::cout << length(sc) << std::endl;
    std::cout << sc << std::endl;

    return 0; 
} 
