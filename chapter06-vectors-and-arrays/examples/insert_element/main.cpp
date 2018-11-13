#include<iostream>
#include<vector>


void print(const std::vector<int> &v)
{
    for(int i=0;i < v.size();i++)
        std::cout << v[i] << std::endl;

}

int find_first(std::vector<int> &v,int value)
{
   int pos = -1;
   for(int i=0;i<v.size();i++)
   {
   		if(v[i] == value)
		{
			pos = i;
			break;
		}
   }
   return pos;
}

int find_first_greater(std::vector<int> &v,int value)
{
   int pos = -1;
   for(int i=0;i<v.size();i++)
   {
   		if(v[i] < value)
		{
			pos = i;
			break;
		}
   }
   return pos;
}

void insert(std::vector<int> &v, int value,int pos)
{
   int last = v.size() - 1; 
   v.push_back(v[last]); 
   for (int i = last; i > pos; i--)
       v[i] = v[i - 1]; 
   v[pos] = value;
}

void fill(std::vector<int> &v)
{
    v.push_back(29000); // 0 
    v.push_back(32000); // 1
    v.push_back(35000); // 2
    v.push_back(44500); // 3
    v.push_back(54000); // 4
    v.push_back(65000); // 5
    v.push_back(67500); // 6
    v.push_back(80000); // 7
    v.push_back(100000); // 8
    v.push_back(115000); // 9
}

int main()
{
    std::vector<int> salary;

    fill(salary);
    print(salary);
	insert(salary,60000,5);
    std::cout << "---------------" << std::endl;
    print(salary);
    return 0;
}

