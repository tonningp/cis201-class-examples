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
   int max_value = v[0];
   for(int i=1;i<v.size();i++) 
        if(v[i] > max_value)
            max_value = v[i];
   return max_value;
}

int min(const std::vector<int> &v)
{
   int min_value = v[0];
   for(int i=1;i<v.size();i++) 
        if(v[i] < min_value)
            min_value = v[i];
   return min_value;
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
    std::vector<int> salary;

    fill(salary);
    print(salary);

    std::cout << std::endl;
    std::cout << "Max: " << max(salary) << std::endl;
    std::cout << "Min: " << min(salary) << std::endl;
    std::cout << "Average: " << average(salary) << std::endl;
    std::cout << "Total: " << sum(salary) << std::endl;

    return 0;
}

