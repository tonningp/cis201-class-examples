#include<iostream>

/**
0   0
1   1
2   4
3   9
4   16
5   25
6   36
...
*/
void print_squares(int size)
{
  for(int i=0;i<size;i++)  
    std::cout << i << '\t' << i*i << std::endl;
}

void print_cubes(int size)
{
  for(int i=0;i<size;i++)  
    std::cout << i << '\t' << i*i*i << std::endl;
}

int main()
{
    print_squares(10);
    print_cubes(10);

    return 0;
}
