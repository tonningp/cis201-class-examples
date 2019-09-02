#include <iostream>
#include <string>

using namespace std;

int main()
{
   cout << "Enter a string: ";
   string str;
   cin >> str;

   int position;
   int length;
   if (str.length() % 2 == 1)
   {
      position = str.length() / 2;
      length = 1;
   }
   else
   {
      position = str.length() / 2 - 1;
      length = 2;
   }
   string result = str.substr(position, length);

   cout << "Middle: " << result << endl;
   return 0;
}
