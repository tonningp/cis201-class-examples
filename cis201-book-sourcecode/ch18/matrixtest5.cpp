#include "matrix5.h"

using std::cout;
namespace mat = BigCPlusPlus_Matrix;

int main()
{
   mat::Matrix m(3, 3);
   m[0][0] = m[1][1] = m[2][2] = 1;
   m[0][1] = m[1][2] = 2;
   cout << 2 * m + m * m;
   try
   {
      m[4][2] = 7; // Purposeful subscript error
   }
   catch (mat::Matrix::IndexException& e)
   {
      cout << "Caught exception: " << e.what() << "\n";
   }
   return 0;
}
