#include <iostream>

using namespace std;

template<typename T>
void print(ostream& out, T data[], int size)
{
   for (int i = 0; i < size; i++)
   {
      if (i > 0) { out << ", "; }
      out << data[i];
   }
   out << endl;
}

int main()
{
   int a[] = { 2, 4, 5 };
   print<int>(cout, a, 3);
   
   return 0;
}
