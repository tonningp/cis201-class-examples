#include<iostream> 
#include<cmath> 

typedef double (*DoubleFnPtr)(double);

double square(double x)
{
    return x * x;
}

double cube(double x)
{
    return x * x * x;
}

double somefunction(double x)
{
    return 2 * x + 1;
}

double anotherline(double x)
{
    return 4 * x + 20;
}

double trig(double x)
{
    return sin(x);
}

//double print(DoubleFnPtr f,int range)
double print(double(*func)(double),int range)
{
   for(int i=0;i<range;i++) 
      std::cout << i << '\t' << func(i) << std::endl;
}


int main()
{
/*
    std::cout << "square(x)" << std::endl;
    print(square,10);
    std::cout << "---------" << std::endl;
    std::cout << "cube(x)" << std::endl;
    print(cube,10);
    std::cout << "somefunction(x)" << std::endl;
    print(somefunction,10);
    std::cout << "----------------------" << std::endl;
    std::cout << "anotherline(x)" << std::endl;
    print(anotherline,10);
    */
    double (*alias_to_trig)(double) = trig;
    std::cout << "trig(x)" << std::endl;
    print(alias_to_trig,100);


    return 0;
}

