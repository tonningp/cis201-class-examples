#include<iostream>
#include<vector>


void print(const std::vector<int> &v)
{
    for(int i=0;i < v.size();i++)
        std::cout << v[i] << std::endl;
}

void fill(std::vector<int> &v)
{
    v.push_back(30000);
    v.push_back(31000);
    v.push_back(32000);
    v.push_back(33000);
    v.push_back(34000);
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
    fill(salary);
    print(salary);
    
    return 0;
}

