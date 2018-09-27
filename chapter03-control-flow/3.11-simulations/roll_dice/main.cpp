#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

const int SCALE = 6;
const int SHIFT = 1;
const int UPPER_LIMIT = 1000000;

int main()
{
    srand(time(0));
    // declare the counters
    int one=0,two=0,three=0,four=0,five=0,six=0;
    
    for(int i=0;i<UPPER_LIMIT;i++)
    {
        int r_number = rand() % SCALE + SHIFT;
        if(r_number == 1) 
        {
            one++;
        }
        else if (r_number == 2)
        {
            two++;
        }
        else if (r_number == 3)
        {
            three++;
        }
        else if (r_number == 4)
        {
            four++;
        }
        else if (r_number == 5)
        {
            five++;
        }
        else if (r_number == 6)
        {
            six++;
        }
        else
        {
            cout << "We have a problem with the random number." << endl;
        }

    }
    cout << "one = " << one << " " <<  one / static_cast<double>(UPPER_LIMIT)<< endl;
    cout << "two = " << two << " " << two / static_cast<double>(UPPER_LIMIT) << endl;
    cout << "three = " << three << " "  <<  three / static_cast<double>(UPPER_LIMIT) << endl;
    cout << "four = " << four << " " << four / static_cast<double>(UPPER_LIMIT) << endl;
    cout << "five = " << five << " " << five / static_cast<double>(UPPER_LIMIT)<<endl;
    cout << "six = " << six << " " << six / static_cast<double>(UPPER_LIMIT) << endl;

    return 0;
}
