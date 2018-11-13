#include<iostream>
#include<vector>


void print_matrix(std::vector<std::vector<int> > &matrix)
{
    for(int row=0;row<matrix.size();row++)
    {
       for(int col=0;col<matrix[row].size();col++)
            std::cout << matrix[row][col] << " ";
       std::cout << std::endl;
    }   
}

int main()
{
    std::vector<std::vector<int> > m_vector;
    std::vector<int> row;
    row.push_back(1);
    row.push_back(0);
    row.push_back(0);
    m_vector.push_back(row);
    row.clear();
    row.push_back(0);
    row.push_back(1);
    row.push_back(0);
    m_vector.push_back(row);
    row.clear();
    row.push_back(0);
    row.push_back(0);
    row.push_back(1);
    m_vector.push_back(row);

    print_matrix(m_vector);

    return 0;
}

