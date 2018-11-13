#include<iostream>
#include<string>



int main()
{
    std::string s = "abdcefg";
    s.push_back('h');
    s.push_back('i');
    std::cout << s.find_first_of("cd") << std::endl;


    return 0;
}

