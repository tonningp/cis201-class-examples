#include <iomanip>
#include "matrix1.h"

Matrix::Matrix()
{
   for (int i = 0; i < ROWS; i++)
      for (int j = 0; j < COLUMNS; j++)
         (*this)(i, j) = 0;
}
   
Matrix& Matrix::operator+=(const Matrix& right)
{
   for (int i = 0; i < ROWS; i++)
      for (int j = 0; j < COLUMNS; j++)
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
   Matrix result;
   for (int i = 0; i < Matrix::ROWS; i++)
      for (int j = 0; j < Matrix::COLUMNS; j++)
         for (int k = 0; k < Matrix::COLUMNS; k++)         
            result(i, j) += left(i, k) * right(k, j); 
   return result;
}
   
Matrix operator*(const Matrix& left, double right)
{
   Matrix result;
   for (int i = 0; i < Matrix::ROWS; i++)
      for (int j = 0; j < Matrix::COLUMNS; j++)
         result(i, j) = left(i, j) * right; 
   return result;
}
   
ostream& operator<<(ostream& left, const Matrix& right)
{
   const int WIDTH = 10;
   for (int i = 0; i < Matrix::ROWS; i++)
   {
      for (int j = 0; j < Matrix::COLUMNS; j++)
         left << setw(WIDTH) << right(i, j);
      left << "\n";
   }
   return left;
}

