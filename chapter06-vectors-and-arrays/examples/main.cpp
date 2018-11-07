#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>

int get_random(int upper)
{
    return rand() % upper + 1;
}

void print(const std::vector<int> &v) 
{
    for(int i=0;i<v.size();i++)
        std::cout << v[i] << std::endl;
}
    
int main()
{
    srand(time(0));
    std::vector<int> v;
    for(int i=0;i<10;i++)
        v.push_back(get_random(100));
    for(int i=0;i<10;i++)
    {
        std::cout << v[i] << std::endl;
        v.pop_back();
    }
    print(v);
}
