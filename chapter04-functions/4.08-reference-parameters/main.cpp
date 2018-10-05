#include<iostream>
#include<string>

using namespace std;


void get_int(int &x);
void print_string(const string &s);


int main()
{
   string s = "World";

   print_string("Hello");
   print_string(s);

   return 0;
}

void print_string(const string &s)
{
    cout << s << endl;
}

void get_int(int &x)
{
    cin >> x;
}

