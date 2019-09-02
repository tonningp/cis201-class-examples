#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H

#include <string>

using namespace std;

const int BLACK = 1;
const int RED = 0;
const int NEGATIVE_RED = -1;
const int DOUBLE_BLACK = 2;

/**
   A node of a red-black tree stores a data item and references
   of the child nodes to the left and to the right. The color
   is the "cost" of passing the node; 1 for black or 0 for red.
   Temporarily, it may be set to 2 or -1. 
*/
class Node
{
public:   
   /**
      Constructs a red node with no data.
   */
   Node();
      
private:
   /**
      Adds a node as a child of this node.
      @param new_node the node to add
   */
   void add_node(Node* new_node);
public: // These members are public for testing  
   /**
      Sets the left child and updates its parent reference.
      @param child the new left child
   */
   void set_left_child(Node* child);

   /**
      Sets the right child and updates its parent reference.
      @param child the new right child
   */
   void set_right_child(Node* child);

   string data;
   Node* left;
   Node* right;
   Node* parent;
   int color;
   
friend class RedBlackTree;
};

/*
   This class implements a red-black tree.
*/
class RedBlackTree
{  
public: 
   /**
      Constructs an empty tree.
   */
   RedBlackTree();
   
   /**
      Inserts a new element into the tree.
      @param element the element to insert
   */
   void insert(string element); 

   /**
      Tries to find an element in the tree.
      @param element the element to find
      @return 1 if the element is contained in the tree, 0 otherwise
   */
   int count(string element) const;
   
   /**
      Tries to remove an element from the tree. Does nothing
      if the element is not contained in the tree.
      @param element the element to remove
   */
   void erase(string element);

   /**
      Prints the contents of the tree in sorted order.
   */
   void print() const;
   
private:
   /**
      Prints a node and all of its descendants in sorted order.
      @param parent the root of the subtree to print
   */
   void print(Node* parent) const;
   
   /**
      Updates the parent's and replacement node's 
      links when this node is replaced.
      Also updates the root reference if it is replaced.
      @param to_be_replaced the node that is to be replaced
      @param replacement the node that replaces that node
   */
   void replace_with(Node* to_be_replaced, Node* replacement);

   /**
      Restores the tree to a red-black tree after a node has been added.
      @param new_node the node that has been added
   */
   void fix_after_add(Node* new_node);

   /** 	
     Fixes the tree so that it is a red-black tree after a node has been removed.
     @param to_be_removed the node that is to be removed
   */
   void fix_before_remove(Node* to_be_removed);
   
   /**
      Move a charge from two children of a parent.
      @param parent a node with two children, or 
      nullptr (in which case nothing is done)
   */
   void bubble_up(Node* parent);

   /**
      Fixes a negative-red or double-red violation introduced by bubbling up.
      @param child the child to check for negative-red 
      or double-red violations
      @return true if the tree was fixed
   */
   bool bubble_up_fix(Node* child);
   
   /**
      Fixes a "double red" violation.
      @param child the child with a red parent
   */
   void fix_double_red(Node* child);
   
   /**
      Fixes a "negative red" violation.
      @param neg_red the negative red node
   */
   void fix_negative_red(Node* neg_red);

public: // for testing
   Node* root; 
};

#endif
