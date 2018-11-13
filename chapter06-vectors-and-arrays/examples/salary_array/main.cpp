#include<iostream>
#include<vector>


void print(int v[],int size)
{
    for(int i=0;i < size;i++)
        std::cout << v[i] << std::endl;

}


void fill(int v[],int size)
{
    for(int i=0;i < size;i++)
       std::cin >> v[i];
}

int max(int v[], int size)
{
   int max_value = v[0];
   for(int i=1;i<size;i++) 
        if(v[i] > max_value)
            max_value = v[i];
   return max_value;
}

int min(int v[],int size)
{
   int min_value = v[0];
   for(int i=1;i<size;i++) 
        if(v[i] < min_value)
            min_value = v[i];
   return min_value;
}

int sum(int v[],int size)
{
   int total = 0;
   for(int i=0;i<size;i++) 
      total += v[i];
   return total;
}

int average(int v[],int size)
{
    return sum(v,10) / size;
}


int main()
{
    int salary[5];
    
    salary[0] = 10000;
    salary[1] = 20000;
    salary[2] = 30000;
    salary[3] = 40000;
    salary[4] = 50000;

    std::cout << salary << std::endl;

/*
    fill(salary,10);
    print(salary,10);

    std::cout << std::endl;
    std::cout << "Max: " << max(salary,10) << std::endl;
    std::cout << "Min: " << min(salary,10) << std::endl;
    std::cout << "Average: " << average(salary,10) << std::endl;
    std::cout << "Total: " << sum(salary,10) << std::endl;
   */

    return 0;
}

