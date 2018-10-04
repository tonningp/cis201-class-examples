#include<iostream>
#include<cmath>
#include<string>

using namespace std;


double get_double(string prompt);
double sphere_volume(double r);

int main()
{
   
   double radius = get_double("Please enter the radius: ");
   cout << radius << endl;
   cout << sphere_volume(radius) << endl;
   double height = get_double("Enter the height: ");
   cout << height << endl;
   return 0;
}

double sphere_volume(double r)
{
   return 4.0/3.0  * M_PI * pow(r,3);
}

/**
   Will get a valid double from the user > 0
   @param prompt  the string prompt
   @return the value that is returned from the user
*/
double get_double(string prompt)
{
    double value;
    cout << prompt;
    cin >> value;
    return value;
}
