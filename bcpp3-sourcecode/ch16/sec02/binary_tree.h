#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <string>

using namespace std;

class Node
{
private:
   string data;
   Node* left;
   Node* right;
friend class BinaryTree;   
};

/*
   A binary tree in which each node has two children.
*/
class BinaryTree
{
public:
   /**
      Constructs an empty tree.
   */
   BinaryTree();
   
   /**
      Constructs a tree with one node and no children.
      @param root_data the data for the root
   */
   BinaryTree(string root_data);

   /**
      Constructs a binary tree.
      @param root_data the data for the root
      @param left the left subtree
      @param right the right subtree
   */
   BinaryTree(string root_data, BinaryTree left, BinaryTree right);
 
   /**
      Returns the height of this tree.
      @return the height
   */
   int height() const;

   /**
      Checks whether this tree is empty.
      @return true if this tree is empty
   */
   bool empty() const;

   /**
      Gets the data at the root of this tree.
      @return the root data
   */
   string data() const;
   
   /**
      Gets the left subtree of this tree.
      @return the left child of the root
   */
   BinaryTree left() const;

   /**
      Gets the right subtree of this tree.
      @return the right child of the root
   */
   BinaryTree right() const;
   
private:
   /**
      Returns the height of the subtree whose root is the given node.
      @param n a node or nullptr
      @return the height of the subtree, or 0 if n is nullptr
   */
   int height(const Node* n) const;
   
   Node* root;
};

#endif
