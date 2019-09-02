#include <iostream>
#include <string>

using namespace std;

int main()
{  
   string e_acute = u8"\U000000e9";
   string high_speed_train = u8"\U0001f684";
   string message = u8"San Jos\U000000e9 \U0001f684";
   cout << "Length of " << e_acute << ": " << e_acute.length() << endl;
   cout << "Length of " << high_speed_train << ": "
      << high_speed_train.length() << endl;
   cout << "Length of " << message << ": " << message.length() << endl;
   size_t pos = message.find(e_acute);
   if (pos != string::npos)
   {
      cout << message << " has " << e_acute
         << " starting at position " <<  pos << endl;
   }
   return 0;
}
