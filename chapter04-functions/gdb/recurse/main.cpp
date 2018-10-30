#include<iostream>
 
using namespace std;
 
long factorial(int n);
 
int main()
{
    int n(0);
    cin>>n;
    long val=factorial(n);
    cout<< val << endl;
    cin.get();
    return 0;
}


long factorial(int n)
{
    if(n>0)
        return n * factorial(n-1);
    else
        return 1;
}
