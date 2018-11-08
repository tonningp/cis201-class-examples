#include<iostream>


int gcd(int a, int b)
{
    while (b != 0)
    {
       int t = b; 
       b = a % b; 
       a = t; 
   }
   return a;
}

int rgcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return rgcd(b,a % b);
}


int main()
{
    std::cout << gcd(124,240) << std::endl;
    std::cout << rgcd(124,240) << std::endl;

    return 0;
}
