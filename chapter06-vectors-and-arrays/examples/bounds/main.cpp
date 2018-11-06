#include<iostream>
#include<vector>


void print(const std::vector<int> &v)
{
    for(int i=0;i <= v.size();i++)
        std::cout << v[i] << std::endl;

}

void fill(std::vector<int> &v,int number)
{

}

int max(const std::vector<int> &v)
{
   int max_value = -1;
   for(int i=0;i<v.size();i++) 
        if(v[i] > max_value)
            max_value = v[i];
   return max_value;
}

int main()
{
    std::vector<int> salary;
    
    salary.push_back(1000);

    std::cout << salary[0] << std::endl;

    return 0;
}

