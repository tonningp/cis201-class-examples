#include<iostream>
#include<cmath>

using namespace std;

double future_value(double initial,double p,int term);

int main()
{

   double balance = future_value(1000,5,10);
   cout << balance << endl;
   cout << abs(-1.0) << endl;
   return 0;
}

double future_value(double initial,double p,int term)
{
    double b = initial * pow(1 + p / 100.0,term);
    return b;
}

