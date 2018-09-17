#include <iomanip>
#include "matrix2.h"

Matrix::Matrix(int r, int c) 
   : rows(r), columns(c), elements(new double[rows * columns])
{
   for (int i = 0; i < rows * columns; i++)
      elements[i] = 0;
}
   
Matrix& Matrix::operator=(const Matrix& other) 
{
   if (this != &other)
   {
      free();
      copy(other);
   }
   return *this;
}

void Matrix::copy(const Matrix& other)
{
   rows = other.rows;
   columns = other.columns;
   elements = new double[rows * columns];
   for (int i = 0; i < rows * columns; i++)
      elements[i] = other.elements[i];
}

Matrix& Matrix::operator+=(const Matrix& right)
{
   assert(rows == right.rows && columns == right.columns);
   for (int i = 0; i < rows; i++)
      for (int j = 0; j < columns; j++)
         (*this)(i, j) += right(i, j);
   return *this;
}

Matrix operator+(const Matrix& left, const Matrix& right)
{
   Matrix result = left;
   result += right;
   return result;
}
   
Matrix operator*(const Matrix& left, const Matrix& right)
{
   assert(left.get_columns() == right.get_rows());
   Matrix result(left.get_rows(), right.get_columns());
   for (int i = 0; i < left.get_rows(); i++)
      for (int j = 0; j < right.get_columns(); j++)
         for (int k = 0; k < left.get_columns(); k++)         
            result(i, j) += left(i, k) * right(k, j); 
   return result;
}
   
Matrix operator*(const Matrix& left, double right)
{
   Matrix result(left);
   for (int i = 0; i < result.get_rows(); i++)
      for (int j = 0; j < result.get_columns(); j++)
         result(i, j) *= right; 
   return result;
}
   
ostream& operator<<(ostream& left, const Matrix& right)
{
   const int WIDTH = 10;
   for (int i = 0; i < right.get_rows(); i++)
   {
      for (int j = 0; j < right.get_columns(); j++)
         left << setw(WIDTH) << right(i, j);
      left << "\n";
   }
   return left;
}

