#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

/**
   Encrypts a stream using the Caesar cipher.
   @param in the stream to read from
   @param out the stream to write to
   @param k the encryption key
*/
void encrypt_file(ifstream& in, ofstream& out, int k)
{  
   char ch;
   while (in.get(ch))
   {
      out.put(ch + k);
   }
}

int main(int argc, char* argv[])
{  
   int key = 3;
   int file_count = 0; // The number of files specified
   ifstream in_file;
   ofstream out_file;

   for (int i = 1; i < argc; i++) // Process all command-line arguments
   {  
      string arg = argv[i]; // The currently processed argument
      if (arg == "-d") // The decryption option
      { 
         key = -3; 
      }
      else // It is a file name
      {  
         file_count++;
         if (file_count == 1) // The first file name
         {  
            in_file.open(arg);
            if (in_file.fail()) // Exit the program if opening failed
            { 
               cout << "Error opening input file " << arg << endl;
               return 1;
            }
         }
         else if (file_count == 2) // The second file name
         {  
            out_file.open(arg);
            if (out_file.fail()) 
            { 
               cout << "Error opening output file " << arg << endl;
               return 1;
            }
         }
      }
   }

   if (file_count != 2) // Exit if the user didn't specify two files
   { 
      cout << "Usage: " << argv[0] << " [-d] infile outfile" << endl;
      return 1;
   }

   encrypt_file(in_file, out_file, key);
   return 0;
}
