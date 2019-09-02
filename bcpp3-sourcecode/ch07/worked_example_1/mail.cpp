#include <cctype>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int VAR_LENGTH = 20;

/**
   Prepares a letter template for a mass mailing.
   @param letter a string with placeholders 0 ... 9 (which will be 
   replaced with null terminators)
   @param vars a two-dimensional array for holding the variable parts of the letter
   @return a vector of fragments, pointing alternately to strings in the letter 
   template and in the variable array
 */
vector<char*> prepare_mailing(char* letter, char vars[][VAR_LENGTH])
{
   vector<char*> fragments;
   char* fragment_start = letter;
   for (char* p = letter; *p != '\0'; p++)
   {
      if (isdigit(*p))
      {
         fragments.push_back(fragment_start);
         fragment_start = p + 1;
         int var_index = *p - '0';
         fragments.push_back(vars[var_index]);
         *p = '\0';
      }
   }
   fragments.push_back(fragment_start);
   return fragments;
}


int main()
{
   char variable_parts[10][VAR_LENGTH];

   strcpy(variable_parts[0], "Ms.");
   strcpy(variable_parts[1], "Sally");
   strcpy(variable_parts[2], "Smith");
   strcpy(variable_parts[3], "123 Main Street");
   strcpy(variable_parts[4], "Anytown");
   strcpy(variable_parts[5], "NY");
   strcpy(variable_parts[6], "12345");

   char letter_template[] = "To: 0 1 2\n3\n4, 5 6\n\nDear 0 2: \n\n"
      "The 2 family may be the lucky winner in the C++ sweepstakes.\n"
      "Wouldn't it be exciting if you were the first 4 residents\n"
      "to use ACME's new C++ development environment? etc. etc. \n\n\n";

   vector<char*> fragments = prepare_mailing(letter_template, variable_parts);

   for (int i = 0; i < fragments.size(); i++)
   {
      cout << fragments[i];      
   }
 
   strcpy(variable_parts[0], "Mr.");
   strcpy(variable_parts[1], "Harry");
   strcpy(variable_parts[2], "Morgan");
   strcpy(variable_parts[3], "456 Park Ave");
   strcpy(variable_parts[4], "Everyville");
   strcpy(variable_parts[5], "KS");
   strcpy(variable_parts[6], "67890");

   for (int i = 0; i < fragments.size(); i++)
   {
      cout << fragments[i];      
   }

   return 0;
}
