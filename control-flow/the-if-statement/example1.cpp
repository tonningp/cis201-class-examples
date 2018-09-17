/**
File: example1.cpp
Description: Example code for if statements
Author: Paul Tonning
*/
#include<iostream>
#include<cmath>

double cubic(double d)
{
   return pow(d,3);
}

int main()
{
   std::cout << cubic(10) << std::endl;
   return 0;
}
