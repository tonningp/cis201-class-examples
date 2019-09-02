#include <iostream>
#include <vector>

using namespace std;

int main()
{
   vector<int> values = {1, 4, 9, 16, 25, 36};

   // In this loop, v is set to each element of the vector.
   for (int v : values)
   {
      cout << v << " ";
   }
   cout << endl;

   // Here, v becomes a reference to each value, which allows you
   // to modify the vector.
   for (int& v : values)
   {
      v += 1;
   }

   // You can use auto instead of the element type.
   for (auto v : values)
   {
      cout << v << " ";
   }
   cout << endl;

   // Use auto& if you want to modify the elements.
   for (auto& v : values)
   {
      v += 1;
   }

   // This is the traditional way of visiting all elements.
   for (int i = 0; i < values.size(); i++)
   {
      cout << values[i] << " ";      
   }
   cout << endl;

   // The "range based" for loop also works with arrays.
   int primes[] = { 2, 3, 5, 7, 11, 13 };
   for (int p : primes)
   {
      cout << p << " ";
   }
   cout << endl;
   
   return 0;
}
