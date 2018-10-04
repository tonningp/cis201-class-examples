#include<iostream>
#include<cmath>

using namespace std;

double future_value(double initial,double p,int term);


int main()
{

   double initial = 1000.00,p=5.0;
   int term = 10;
   cout << start_balance << endl;
   double balance = future_value(initial,p,term);

   cout << balance << endl;

   return 0;
}

double future_value(double initial,double p,int term)
{
    return initial * pow(1 + p / 100.0,term);
}

