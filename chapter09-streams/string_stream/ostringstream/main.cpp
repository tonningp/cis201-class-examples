#include<iostream>
#include<fstream>
#include<sstream>


std::ostream& build_stream(std::ostream &o)
{
    o << 1 << "\n";
    o << 2 << "\n";
    o << 3 << "\n";
    o << 4 << "\n";
    o << std::hex << 65535 << "\n";
    o << 25.2 << "\n";
    o << 30.1;

    return o;
}

int main()
{
    std::ostringstream ostring;

    build_stream(ostring);
    std::cout << ostring.str() << std::endl;

    build_stream(std::cout);

    std::ofstream f("data.txt");
    build_stream(f);
    f.close();

/*
    ostring << 1
            << " "
            << 23.5
            << " "
            << 2
            << " "
            << "Hello"
            << std::endl;

    std::cout << ostring.str() << std::endl;

*/
    
    

    return 0;
}
