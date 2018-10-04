#include<iostream>
#include<string>

using namespace std;

void get_int(string prompt,int &x);

int main()
{
   int the_integer=25;
   cout << "before get_int -- The value is: "<< the_integer << endl;
   get_int("Enter a value: ",the_integer);
   cout << "after get_int -- The value is: "<< the_integer << endl;
   return 0;
}


void get_int(string prompt,int &x)
{
    cout << prompt;
    cin >> x;
}
