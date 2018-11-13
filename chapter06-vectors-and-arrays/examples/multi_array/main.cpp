#include<iostream>
#include<vector>

const int COLSIZE = 10; 

void print_matrix(int matrix[][COLSIZE],int rows,int cols)
{
    for(int row=0;row<rows;row++)
    {
       for(int col=0;col<cols;col++)
            std::cout << matrix[row][col] << " ";
       std::cout << std::endl;
    }   
}

int main()
{
    int matrix[][COLSIZE] = {
        {1,0,0,0,0,0,0,0,0,0},
        {0,1,0,0,0,0,0,0,0,0},
        {0,0,1,0,0,0,0,0,0,0},
        {0,0,0,1,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0}
    };
   

    print_matrix(matrix,10,COLSIZE);

    return 0;
}

