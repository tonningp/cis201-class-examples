#include<iostream>
#include<vector>
#include<iomanip>
#include<cstdlib>
#include<ctime>

void print(std::vector<int> v)
{
    for(int i=0;i<v.size();i++)
    {
        std::cout << v[i] << " ";
        if(i % 10 == 0)  // make it only 10 in a row
           std::cout << std::endl;
    }
    std::cout << std::endl;  
}

int rand_range(int low, int high)
{
      return rand() % (high-low+1) + low;
}

void fill_random(std::vector<int> &v,int number,int low,int high)
{
    for(int i=0;i<number;i++)
      v.push_back(rand_range(low,high));
}

void fill_unique_random(std::vector<int> &v,int number,int low,int high)
{
    for(int i=0;i<number;i++)
    {
        int r;
        bool unique = true;
        do
        {
            r = random() % (high-low+1) + low;
            unique = true;
            for(int j=0;j < v.size();j++)
               if(v[j] == r)
               {
                   unique = false;
                   break;
               }
        }while(!unique);
        v.push_back(r);
    }
     
}

int main()
{  
   
   srand(time(0));
    

   std::vector<int> v1;
   std::vector<int> v2;
   fill_random(v1,100,1,100);
   print(v1);
   std::cout << std::endl;
   std::cout << std::endl;
   fill_unique_random(v2,100,1,100);
   print(v2);
   
   return 0;
}
