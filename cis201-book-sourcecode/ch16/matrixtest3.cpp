#include <string>
#include "matrix3.h"

using namespace std;

int main()
{
   Matrix<double> m(3, 3);
   m[0][0] = m[1][1] = m[2][2] = 1;
   m[0][1] = m[1][2] = 2;
   m[0][2] = m[1][0] = m[2][0] = m[2][1] = 0;
   cout << 2.0 * m + m * m << "\n";
   
   Matrix<string> s(3, 2);
   s[0][0] = "First"; s[0][1] = "Last";
   s[1][0] = "Joan"; s[1][1] = "Jones";
   s[2][0] = "Lisa"; s[2][1] = "Lin";
   cout << s + s;
   
   return 0;
}
