#include "matrix1.h"

int main()
{
   Matrix m;
   m[0][0] = m[1][1] = m[2][2] = 1;
   m(0,1) = m(1,2) = 2;
   cout << 2 * m << "\n";
   cout << m * m << "\n";
   cout << 2 * m + m * m;
   return 0;
}
