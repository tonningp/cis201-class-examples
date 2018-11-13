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

void remove_ordered(std::vector<int> &v, int value)
{
   int pos = find_first(v,value);
   if(pos != -1)
   {
	   for (int i = pos; i < v.size() - 1; i++) 
		  v[i] = v[i + 1];
	   v.pop_back(); 
   }
}

void remove(std::vector<int> &v, int value)
{
   int pos = find_first(v,value);
   if(pos != -1)
   {
       int last_pos = v.size() - 1; 
       v[pos] = v[last_pos];
	   v.pop_back(); 
   }
}

void fill(std::vector<int> &v)
{
    v.push_back(29000);
    v.push_back(32000);
    v.push_back(35000);
    v.push_back(44500);
    v.push_back(54000);
    v.push_back(65000);
    v.push_back(67500);
    v.push_back(80000);
    v.push_back(100000);
    v.push_back(115000);
}



int main()
{
    std::vector<int> salary;

    fill(salary);
    print(salary);
	remove_ordered(salary,54000);
    std::cout << "---------------" << std::endl;
    print(salary);
    return 0;
}

