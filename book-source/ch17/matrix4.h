#ifndef MATRIX4_H
#define MATRIX4_H

#include <iostream>
#include <stdexcept>

using namespace std;

/**
   Matrix exception class for indexing error.
*/
class MatrixIndexException : public out_of_range 
{
public:
   MatrixIndexException(int i);
private:
   string format_message(int i);
};

/**
   Matrix exception class for mismatched argument error.
*/
class MatrixMismatchException : public invalid_argument 
{
public:   
   MatrixMismatchException();
};

/**
   This class describes a row in a matrix.
*/
class Matrix;
class MatrixRow
{
public:
   /**
      Remembers a row for a given matrix.
      @param m a pointer to the matrix
      @param s the size of the row
   */
   MatrixRow(Matrix* m, int s);

   /**
      Accesses a row element.
      @param j the column index
      @return a reference to the element with the given index
   */
   double& operator[](int j) throw (MatrixIndexException);

private:
   Matrix* mat;
   int i;
};

/**
   This class describes a row in a constant matrix.
*/
class ConstMatrixRow
{
public:
   /**
      Constructs a row with a given start and size.
      @param m a pointer to the matrix
      @param s the size of the row
   */
   ConstMatrixRow(const Matrix* m, int s);

   /**
      Accesses a row element.
      @param j the column index
      @return a reference to the element with the given index
   */
   double operator[](int j) const throw (MatrixIndexException);

private:
   const Matrix* mat;
   int i;
};

/**
   This class describes a matrix with arbitrary rows and columns.
*/
class Matrix
{
public:
   /**
      Constructs a matrix filled with zero elements.
   */
   Matrix(int r, int c);

   /**
      The big three
   */
   Matrix(const Matrix& other);
   Matrix& operator=(const Matrix& other);
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
   double& operator()(int i, int j) throw (MatrixIndexException);

   /**
      Accesses a matrix element.
      @param i the row index
      @param j the column index
      @return the element with the given indexes
   */
   double operator()(int i, int j) const throw (MatrixIndexException);

   /**
      Accesses a matrix row.
      @param i the row index
      @return the row with the given index
   */
   MatrixRow operator[](int i) throw (MatrixIndexException);

   /**
      Accesses a matrix row.
      @param i the row index
      @return the row with the given index
   */
   ConstMatrixRow operator[](int i) const throw (MatrixIndexException);

   /**
      Computes the matrix sum.
      @param right another matrix
      @return the updated matrix
   */
   Matrix& operator+=(const Matrix& right) 
      throw (MatrixMismatchException);

private:
   /**
      Copies another matrix into this matrix.
      @param other the other matrix
   */
   void copy(const Matrix& other);

   /**
      Frees the memory for this matrix.
   */
   void free();

   int rows;
   int columns;
   double* elements;
};

/**
   Computes the matrix sum.
   @param right another matrix
   @return the sum of two matrices
*/
   Matrix operator+(const Matrix& left, const Matrix& right) 
      throw (MatrixMismatchException);

/**
   Computes the matrix product.
   @param right another matrix
   @return the product of two matrices
*/
   Matrix operator*(const Matrix& left, const Matrix& right) 
      throw (MatrixMismatchException);

/**
   Computes the scalar product of a scalar value and a matrix.
   @param left a scalar value
   @param right a matrix
   @return the product of the given value and the given matrix
*/
Matrix operator*(double left, const Matrix& right);

/**
   Computes the scalar product of a matrix and a scalar value.
   @param right a scalar value
   @return the product of this matrix and the given value
*/
Matrix operator*(const Matrix& left, double right);

/**
   Prints a matrix to an output stream.
   @param left an output stream
   @param right a matrix
   @return the given output stream
*/
ostream& operator<<(ostream& left, const Matrix& right);

inline MatrixIndexException::MatrixIndexException(int idx)
: out_of_range(format_message(idx)) {}

inline MatrixMismatchException::MatrixMismatchException() 
: invalid_argument("Matrix arguments have incompatible sizes")  {}

inline Matrix::Matrix(const Matrix& other) 
{ 
   copy(other); 
}

inline Matrix::~Matrix() 
{ 
   free(); 
}

inline int Matrix::get_rows() const 
{ 
   return rows; 
}

inline int Matrix::get_columns() const 
{ 
   return columns; 
}

inline void Matrix::free()
{
   delete[] elements;
}

inline MatrixRow Matrix::operator[](int i) throw (MatrixIndexException)
{
   return MatrixRow(this, i);
}   

inline ConstMatrixRow Matrix::operator[](int i) const 
   throw (MatrixIndexException)
{
   return ConstMatrixRow(this, i);
}   
   
inline MatrixRow::MatrixRow(Matrix* m, int s) : mat(m), i(s) { }
   
inline double& MatrixRow::operator[](int j) throw (MatrixIndexException)
{
   return (*mat)(i,j);
}   

inline ConstMatrixRow::ConstMatrixRow(const Matrix* m, int s) 
   : mat(m), i(s) { }

inline double ConstMatrixRow::operator[](int j) const 
   throw (MatrixIndexException)
{
   return (*mat)(i, j);
}   

inline Matrix operator*(double left, const Matrix& right)
{
   return right * left;
}

#endif
