#include<iostream>
#include<string>

using namespace std;

void print_string(const string &s);

int main()
{
   string hello_s = "Hello";
   print_string(hello_s);
   print_string(" World\n");
   return 0;
}


void print_string(const string &s)
{
    cout << s;
}
