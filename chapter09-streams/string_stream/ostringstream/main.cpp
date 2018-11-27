#include<iostream>
#include<sstream>


int main()
{
    std::ostringstream ostring;

    ostring << 1 << "\n";
    ostring << 2 << "\n";
    ostring << 3 << "\n";
    ostring << 4 << "\n";
    ostring << std::hex << 65535 << "\n";
    ostring << 25.2 << "\n";
    ostring << 30.1;

    std::cout << ostring.str() << std::endl;

    return 0;
}
