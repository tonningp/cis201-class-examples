#include<iostream>
#include<cmath>

using namespace std;

double future_value(double initial,double p,int term);

int main()
{

   double balance = future_value(1000,5,10);
   cout << balance << endl;
   return 0;
}

/**
    Calculates the future value of an initial principle according to the given interest rate and term
    @param initial the initial principle
    @param p the interest rate
    @param term the years of the investment
    @return balance
*/
double future_value(double initial,double p,int term)
{
    return initial * pow(1 + p / 100.0,term);
}

