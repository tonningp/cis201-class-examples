#include<iostream>
#include<cmath>
#include<cassert>

using namespace std;

double future_value(double initial,double p,int term);

int main()
{

   double balance = future_value(1000,5,10);
   cout << balance << endl;
   return 0;
}
/**
    Compute the future value of an initial innestment
    @param initial initial balance initial > 0
*/
double future_value(double initial,double p,int term)
{
    assert( initial > 0 );
    assert( p > 0 );
    assert( term > 0 );
    return initial * pow(1 + p / 100.0,term);
}

