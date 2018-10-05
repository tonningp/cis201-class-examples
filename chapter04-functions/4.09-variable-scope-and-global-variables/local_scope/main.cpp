#include<iostream>
#include<cmath>

using namespace std;


void scope_test(int x);


int main() 
{

   int x = 20;
   int y = 30;

   scope_test(x);
   scope_test(x);
   scope_test(x);
   scope_test(x);
   scope_test(x);

   return 0;
}

void scope_test(int x)
{
    x = 10;
    static int y = 0;
    cout << x << endl;
    cout << y << endl;
    y++;
}


