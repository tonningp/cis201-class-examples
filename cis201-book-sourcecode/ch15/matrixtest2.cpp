#include "matrix2.h"

int main()
{
   Matrix m(3, 3);
   m[0][0] = m[1][1] = m[2][2] = 1;
   m[0][1] = m[1][2] = 2;
   Matrix a = 2 * m;
   Matrix b(4, 4);
   b = m * m;
   cout << a << "\n";
   cout << b << "\n";
   cout << a + b;
   return 0;
}
