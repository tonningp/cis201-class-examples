#include<iostream>
#include<cstdlib>
#include<ctime>

/*
pseudocode for bubble sort
   bubble_sort( A : list of sortable items )
   begin
        n = length(A)
        repeat
            swapped = false
            for i = 1 to n-1 inclusive do
              if A[i-1] > A[i] then
                   swap(A[i-1], A[i])
                   swapped = true
               end if
           end for
       until not swapped
   end 
*/

void fill_array(int *array,int size)
{
    for(int i=0;i<size;i++)
        array[i] = rand() % 1000 + 1;

}

void print_array(int *array,int size)
{
    for(int i=0;i<size;i++)
        std::cout << array[i] << std::endl;
}

void swap(int& a,int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

void bubble_sort(int * A, int n)
{
	bool swapped;
    int count=1;
	do
	{
	  swapped = false;
	  for(int i=1;i<n;i++)
	  {
		 if(A[i-1] > A[i]) 
         {
			swap(A[i-1],A[i]);
            swapped = true;
         }
      }
//      std::cout << "pass " << count << std::endl;
//      std::cout << "array(A)= ";
//      print_array(A,n);
//      count++;
      
      //n = n-1;

	} while(swapped);
}

const int ARRAY_SIZE = 10;

int main()
{
    srand(time(0));
    int *array = new int[ARRAY_SIZE];
    fill_array(array,ARRAY_SIZE);
    std::cout << "Before bubble_sort:" << std::endl;
    print_array(array,ARRAY_SIZE);
    bubble_sort(array,ARRAY_SIZE);
    std::cout << "After bubble_sort:" << std::endl;
    print_array(array,ARRAY_SIZE);
	return 0;
}
