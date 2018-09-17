#ifndef MATRIX3_H
#define MATRIX3_H

#include <iostream>
#include <iomanip>
#include <cassert>

using namespace std;

template <typename T> class Matrix;

/**
   This class describes a row in a matrix.
*/
template <typename T> 
class MatrixRow
{
public:
   /**
      Remembers a row for a given matrix.
      @param m a pointer to the matrix
      @param s the size of the row
   */
   MatrixRow(Matrix<T>* m, int s);

   /**
      Accesses a row element.
      @param j the column index
      @return a reference to the element with the given index
   */
   T& operator[](int j);

private:
   Matrix<T>* mat;
   int i;
};

/**
   This class describes a row in a constant matrix.
*/
template <typename T> 
class ConstMatrixRow
{
public:
   /**
      Constructs a row with a given start and size.
      @param m a pointer to the matrix
      @param s the size of the row
   */
   ConstMatrixRow(const Matrix<T>* m, int s);

   /**
      Accesses a row element.
      @param j the column index
      @return a reference to the element with the given index
   */
   T operator[](int j) const;

private:
   const Matrix<T>* mat;
   int i;
};

/**
   This class describes a matrix with arbitrary rows and columns.
*/
template <typename T> 
class Matrix
{
public:
   /**
      Constructs a matrix filled with zero elements.
   */
   Matrix(int r, int c);

   /**
      The big three-copy constructor, assignment operator, and destructor.
   */
   Matrix(const Matrix<T>& other);
   Matrix& operator=(const Matrix<T>& other);
   ~Matrix();

   /**
      Gets the number of rows of this matrix.
      @return the number of rows
   */
   int get_rows() const;
   
   /**
      Gets the number of columns of this matrix.
      @return the number of columns
   */
   int get_columns() const;
   
   /**
      Accesses a matrix element.
      @param i the row index
      @param j the column index
      @return a reference to the element with the given indexes
   */
   T& operator()(int i, int j);

   /**
      Accesses a matrix element.
      @param i the row index
      @param j the column index
      @return the element with the given indexes
   */
   T operator()(int i, int j) const;

   /**
      Accesses a matrix row.
      @param i the row index
      @return the row with the given index
   */
   MatrixRow<T> operator[](int i);   

   /**
      Accesses a matrix row.
      @param i the row index
      @return the row with the given index
   */
   ConstMatrixRow<T> operator[](int i) const;

   /**
      Computes the matrix sum.
      @param right another matrix
      @return the updated matrix
   */
   Matrix<T>& operator+=(const Matrix<T>& right);

private:
   /**
      Copies another matrix into this matrix.
      @param other the other matrix
   */
   void copy(const Matrix<T>& other);

   /**
      Frees the memory for this matrix.
   */
   void free();

   int rows;
   int columns;
   T* elements;
};

/**
   Computes the matrix sum.
   @param right another matrix
   @return the sum of two matrices
*/
template <typename T> 
Matrix<T> operator+(const Matrix<T>& left, const Matrix<T>& right);

/**
   Computes the matrix product.
   @param right another matrix
   @return the product of two matrices
*/
template <typename T> 
Matrix<T> operator*(const Matrix<T>& left, const Matrix<T>& right);

/**
   Computes the scalar product of a scalar value and a matrix.
   @param left a scalar value
   @param right a matrix
   @return the product of the given value and the given matrix
*/
template <typename T> 
Matrix<T> operator*(T left, const Matrix<T>& right);

/**
   Computes the scalar product of a matrix and a scalar value.
   @param right a scalar value
   @return the product of this matrix and the given value
*/
template <typename T> 
Matrix<T> operator*(const Matrix<T>& left, T right);

/**
   Prints a matrix to an output stream.
   @param left an output stream
   @param right a matrix
   @return the given output stream
*/
template <typename T> 
ostream& operator<<(ostream& left, const Matrix<T>& right);

template <typename T> 
inline Matrix<T>::Matrix(const Matrix& other) 
{ 
   copy(other); 
}

template <typename T> 
inline Matrix<T>::~Matrix() 
{ 
   free(); 
}

template <typename T> 
inline int Matrix<T>::get_rows() const 
{ 
   return rows; 
}

template <typename T> 
inline int Matrix<T>::get_columns() const 
{ 
   return columns; 
}

template <typename T> 
inline void Matrix<T>::free()
{
   delete[] elements;
}

template <typename T> 
inline T& Matrix<T>::operator()(int i, int j)
{
   assert(0 <= i && i < rows && 0 <= j && j < columns);
   return elements[i * get_columns() + j];
}

template <typename T> 
inline T Matrix<T>::operator()(int i, int j) const
{
   assert(0 <= i && i < rows && 0 <= j && j < columns);
   return elements[i * get_columns() + j];
}
   
template <typename T> 
inline MatrixRow<T> Matrix<T>::operator[](int i) 
{
   return MatrixRow<T>(this, i);
}   

template <typename T> 
inline ConstMatrixRow<T> Matrix<T>::operator[](int i) const
{
   return ConstMatrixRow<T>(this, i);
}   
   
template <typename T> 
inline MatrixRow<T>::MatrixRow(Matrix<T>* m, int s) : mat(m), i(s) { }
   
template <typename T> 
inline T& MatrixRow<T>::operator[](int j)
{
   return (*mat)(i,j);
}   

template <typename T> 
inline ConstMatrixRow<T>::ConstMatrixRow(const Matrix<T>* m, int s) 
   : mat(m), i(s) { }

template <typename T> 
inline T ConstMatrixRow<T>::operator[](int j) const
{
   return (*mat)(i, j);
}   

template <typename T> 
inline Matrix<T> operator*(T left, const Matrix<T>& right)
{
   return right * left;
}

template <typename T> 
Matrix<T>::Matrix(int r, int c) 
   : rows(r), columns(c), elements(new T[rows * columns])
{
}
   
template <typename T> 
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& other) 
{
   if (this != &other)
   {
      free();
      copy(other);
   }
   return *this;
}

template <typename T> 
void Matrix<T>::copy(const Matrix<T>& other)
{
   rows = other.rows;
   columns = other.columns;
   elements = new T[rows * columns];
   for (int i = 0; i < rows * columns; i++)
      elements[i] = other.elements[i];
}

template <typename T> 
Matrix<T>& Matrix<T>::operator+=(const Matrix<T>& right)
{
   assert(rows == right.rows && columns == right.columns);
   for (int i = 0; i < rows; i++)
      for (int j = 0; j < columns; j++)
         (*this)(i, j) += right(i, j);
   return *this;
}

template <typename T> 
Matrix<T> operator+(const Matrix<T>& left, const Matrix<T>& right)
{
   Matrix<T> result = left;
   result += right;
   return result;
}
   
template <typename T> 
Matrix<T> operator*(const Matrix<T>& left, const Matrix<T>& right)
{
   assert(left.get_columns() == right.get_rows());
   Matrix<T> result(left.get_rows(), right.get_columns());
   for (int i = 0; i < left.get_rows(); i++)
      for (int j = 0; j < right.get_columns(); j++)
         for (int k = 0; k < left.get_columns(); k++)         
            result(i, j) += left(i, k) * right(k, j); 
   return result;
}
   
template <typename T> 
Matrix<T> operator*(const Matrix<T>& left, T right)
{
   Matrix<T> result(left);
   for (int i = 0; i < result.get_rows(); i++)
      for (int j = 0; j < result.get_columns(); j++)
         result(i, j) *= right; 
   return result;
}
   
template <typename T> 
ostream& operator<<(ostream& left, const Matrix<T>& right)
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

#endif
