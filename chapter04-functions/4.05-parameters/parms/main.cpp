#include<iostream>
#include<cmath>
#include<cassert>

using namespace std;

double future_value(double initial,double p,int term);

int main()
{

   double initial = 1000, p = 5;
   double term = 10;

   double balance = future_value(initial,p,term);

   cout << balance << endl;
   return 0;
}

double future_value(double initial,double p,int term)
{
    assert(initial > 0);
    assert(p > 0);
    assert(term > 0);
    return initial * pow(1 + p / 100.0,term);
}

