#include<iostream>

typedef double (*DoubleFnPtr)(double);

double square(double x)
{
    return x * x;
}

double cube(double x)
{
    return x * x * x;
}


double print(DoubleFnPtr f,int range)
{
   for(int i=0;i<range;i++) 
      std::cout << i << '\t' << f(i) << std::endl;
}


int main()
{
    std::cout << "square(x)" << std::endl;
    print(square,10);
    std::cout << "---------" << std::endl;
    std::cout << "cube(x)" << std::endl;
    print(cube,10);


    return 0;
}

