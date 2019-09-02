#ifndef HUFFMAN_TREE_H
#define HUFFMAN_TREE

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Node
{
private:
   char character;
   int frequency;
   Node* left;
   Node* right;
friend class HuffmanTree;   
};

/*
   A tree for decoding Huffman codes.
*/
class HuffmanTree
{
public:
   /**
      Constructs a Huffman tree from given character frequencies.
      @param frequencies a map whose keys are the characters to be encoded
      and whose values are the frequencies of the characters
   */
   HuffmanTree(const unordered_map<char, int>& frequencies);
   /**
      Decodes an encoded string.
      @param input a string made up of 0 and 1
   */
   string decode(string input) const;

   unordered_map<char, string> encoding_map() const;

private:
   Node* remove_min(vector<Node*>& nodes) const;
   void fill_encoding_map(unordered_map<char, string>& map,
      string prefix, Node* n) const;   
   
   Node* root;   
};

#endif
