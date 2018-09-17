#ifndef MATRIX5_H
#define MATRIX5_H

#include <iostream>
#include <stdexcept>

namespace BigCPlusPlus_Matrix 
{

/**
   This class describes a matrix with arbitrary rows and columns.
*/
class Matrix
{
private:
   /**
      Forward reference for classes Row and ConstRow.
   */
   class Row;
   class ConstRow;

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
   double& operator()(int i, int j);

   /**
      Accesses a matrix element.
      @param i the row index
      @param j the column index
      @return the element with the given indexes
   */
   double operator()(int i, int j) const;

   /**
      Accesses a matrix row.
      @param i the row index
      @return the row with the given index
   */
   Row operator[](int i);

   /**
      Accesses a matrix row.
      @param i the row index
      @return the row with the given index
   */
   ConstRow operator[](int i) const;

   /**
      Computes the matrix sum.
      @param right another matrix
      @return the updated matrix
   */
   Matrix& operator+=(const Matrix& right);

   /**
      Forward reference for classes MismatchException and IndexException.
   */
   class MismatchException;
   class IndexException;

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
   This class describes a row in a matrix.
*/
class Matrix::Row
{
public:
   /**
      Remembers a row for a given matrix.
      @param m a pointer to the matrix
      @param s the size of the row
   */
   Row(Matrix* m, int s);

   /**
      Accesses a row element.
      @param j the column index
      @return a reference to the element with the given index
   */
   double& operator[](int j);

private:
   Matrix* mat;
   int i;
};

/**
   This class describes a row in a constant matrix.
*/
class Matrix::ConstRow
{
public:
   /**
      Constructs a row with a given start and size.
      @param m a pointer to the matrix
      @param s the size of the row
   */
   ConstRow(const Matrix* m, int s);

   /**
      Accesses a row element.
      @param j the column index
      @return a reference to the element with the given index
   */
   double operator[](int j) const;

private:
   const Matrix* mat;
   int i;
};

/**
   Matrix exception class: Indexing error
*/
class Matrix::IndexException : public std::out_of_range 
{
public:
   IndexException(int i);
private:
   std::string format_message(int i);
};

/**
   Matrix exception class: Mismatched Argument error
*/
class Matrix::MismatchException : public std::invalid_argument 
{
public:   
   MismatchException();
};

/**
   Computes the matrix sum.
   @param right another matrix
   @return the sum of two matrices
*/
   Matrix operator+(const Matrix& left, const Matrix& right);

/**
   Computes the matrix product.
   @param right another matrix
   @return the product of two matrices
*/
   Matrix operator*(const Matrix& left, const Matrix& right);

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
std::ostream& operator<<(std::ostream& left, const Matrix& right);

inline Matrix::IndexException::IndexException(int idx)
   : out_of_range(format_message(idx)) {}

inline Matrix::MismatchException::MismatchException() 
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

inline Matrix::Row Matrix::operator[](int i)
{
   return Matrix::Row(this, i);
}   

inline Matrix::ConstRow Matrix::operator[](int i) const
{
   return Matrix::ConstRow(this, i);
}   
   
inline Matrix::Row::Row(Matrix* m, int s) : mat(m), i(s) { }

inline double& Matrix::Row::operator[](int j)
{
   return (*mat)(i,j);
}   

inline Matrix::ConstRow::ConstRow(const Matrix* m, int s)
   : mat(m), i(s) { }

inline double Matrix::ConstRow::operator[](int j) const
{
   return (*mat)(i, j);
}   

inline Matrix operator*(double left, const Matrix& right)
{
   return right * left;
}

}
#endif
