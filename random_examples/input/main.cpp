#include<iostream>
#include<string>


using namespace std;


int main()
{
    int a,b,c;
    string input;
    

    cout << "Enter a string: ";
    getline(cin,input);
    cout << "Enter integer a: ";
    cin >> a;
    cout << "Enter integer b: ";
    cin >> b;
    cout << "Enter integer c: ";
    cin >> c;


    cout << "a b and c" 
         << a << " "
         << b << " "
         << c << endl;

    return 0;
}
