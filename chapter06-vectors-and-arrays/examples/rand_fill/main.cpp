#include<iostream>
#include<ctime>
#include<cstdlib>
#include<vector>


void print(const std::vector<int> &v)
{
    for(int i=0;i < v.size();i++)
        std::cout << v[i] << std::endl;

}

int rand_range(int low,int high)
{
   return  rand() % (high-low+1) + low;
}

void fill(std::vector<int> &v,int number,int low,int high)
{
    for(int i=0;i<number;i++)
        v.push_back(rand_range(low,high));
}

int min(const std::vector<int> &v)
{
   int min_value = v[0];
   for(int i=0;i<v.size();i++) 
        if(v[i] < min_value)
            min_value = v[i];
   return min_value;
}

int max(const std::vector<int> &v)
{
   int max_value = -1;
   for(int i=0;i<v.size();i++) 
        if(v[i] > max_value)
            max_value = v[i];
   return max_value;
}

int sum(const std::vector<int> &v)
{
   int total = 0;
   for(int i=0;i<v.size();i++) 
      total += v[i];
   return total;
}

int average(const std::vector<int> &v) 
{
    return sum(v) / v.size();
}

int main()
{
    srand(time(0));
    std::vector<int> salary;

    fill(salary,10,20000,120000);
    print(salary);
    std::cout << std::endl
              << std::endl
              << "Min: "   << min(salary)
              << std::endl << "Max: "  << max(salary)
              << std::endl
              << "Total: " << sum(salary)
              << std::endl
              << "Average: " << average(salary)
              << std::endl;


    return 0;

}

