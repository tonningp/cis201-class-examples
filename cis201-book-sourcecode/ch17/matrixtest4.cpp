#include "matrix4.h"

int main()
{
   try
   {
      Matrix m(4, 3);
      m[0][0] = m[1][1] = m[2][2] = 1;
      m[0][1] = m[1][2] = m[2][3] = 2;
      cout << m * m;
   }
   catch (exception& e)
   {
      cout << "Caught exception: " << e.what() << "\n";
   }
   return 0;
}
