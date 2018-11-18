#include<iostream>

void print_array(double *ar,int size)
{
    for(int i=0;i<size;i++)
        std::cout << ar[i] << std::endl;
}

void array_function()
{
    double *ar = new double[10];
    delete [] ar;
}

const int SIZE = 5;
int main()
{
    double *d_array = new double[SIZE];
    d_array[0]   = 3.14159;
    d_array[1]   = 2.71828;
    d_array[2]   = 1.41421;
    d_array[3]   = 1.61803;
    d_array[4]   = 2.23606;
    print_array(d_array,SIZE);

    delete [] d_array;
    return 0;
}

