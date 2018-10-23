#include<iostream>
 
using namespace std;
 
unsigned long factorial(int n);
 
int main()
{
    int n = 0 ;
    cin >> n;
    long val=factorial(n);
    cout<< val << endl;
    cin.get();
    return 0;
}


unsigned long factorial(int n)
{
    unsigned long result = 1;
    while(n > 0)
    {
        result *= n;
        n--;
    }
    return result;
}
