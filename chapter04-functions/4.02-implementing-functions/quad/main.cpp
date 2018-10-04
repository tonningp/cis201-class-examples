#include<iostream>

using namespace std;

double quad(double a,double x,double b,double c);

int main()
{
   for(double x = -2.0;x <= 2.0;x += 0.1)
   {
        cout << x 
             << "\t" 
             << quad(1,x,2,1) 
             << endl; 
   }
   return 0;
}


double quad(double a,double x,double b,double c)
{
    return a * x * x + b * x + c;
}
