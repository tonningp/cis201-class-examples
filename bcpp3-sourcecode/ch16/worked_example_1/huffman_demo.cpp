#include <iostream>
#include <string>
#include <unordered_map>
#include "huffman_tree.h"

using namespace std;

string encode(string to_encode,
   const unordered_map<char, string>& encoding_map)
{
   string result = "";
   for (int i = 0; i < to_encode.length(); i++)
   {
      char ch = to_encode[i];
      string encoded = encoding_map.at(ch);
      result = result + encoded;
   }
   return result;
}

int main()
{
   unordered_map<char, int> frequency_map;
   frequency_map['A'] = 2089;
   frequency_map['E'] = 576;
   frequency_map['H'] = 357;
   frequency_map['I'] = 671;
   frequency_map['K'] = 849;
   frequency_map['L'] = 354;
   frequency_map['M'] = 259;
   frequency_map['N'] = 660;
   frequency_map['O'] = 844;
   frequency_map['P'] = 239;
   frequency_map['U'] = 472;
   frequency_map['W'] = 74;
   frequency_map['\''] = 541;
   HuffmanTree tree(frequency_map);

   unordered_map<char, string> encoding_map = tree.encoding_map();
   string encoded = encode("ALOHA", encoding_map);
   cout << encoded << endl;
   string decoded = tree.decode(encoded);
   cout << decoded << endl;
   return 0;
}
