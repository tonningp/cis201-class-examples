#include<iostream>
#include<vector>


void print(const std::vector<int> &v)
{
    for(int i=0;i < v.size();i++)
        std::cout << v[i] << std::endl;

}

void fill(std::vector<int> &v)
{
    v.push_back(32000);
    v.push_back(54000);
    v.push_back(67500);
    v.push_back(29000);
    v.push_back(35000);
    v.push_back(80000);
    v.push_back(115000);
    v.push_back(44500);
    v.push_back(100000);
    v.push_back(65000);
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
    std::cout << std::endl;
    std::cout << "Max: " << max(salary) << std::endl;

    return 0;
}

