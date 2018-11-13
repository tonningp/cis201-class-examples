#include<iostream>

void print(int ar[],int size)
{
    for(int i=0;i<size;i++)
        std::cout << ar[i] << std::endl;
}

int main()
{
   int salary[] = {
     25000,
     30000,
     40000,
     20000,
     25000,
     30000,
     40000,
     20000,
     20000,
     25000,
     30000,
     40000,
     20000
   };

   print(salary,5);
   return 0;
}
