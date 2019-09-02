#include <iostream>
#include <string>

using namespace std;

/**
   This program removes spaces and dashes from a credit card number.
*/
int main()
{
   string credit_card_number = "4123-5678-9012-3450";
      
   int i = 0;
   while (i < credit_card_number.length())
   {
      string ch = credit_card_number.substr(i, 1);
      if (ch == " " || ch == "-")         
      {
         // Remove the character at position i

         string before = credit_card_number.substr(0, i);
         string after = credit_card_number.substr(i + 1);
         credit_card_number = before + after;
      }
      else
      {
         i++;
      }
   }
      
   cout << credit_card_number << endl;      
   return 0;
}
