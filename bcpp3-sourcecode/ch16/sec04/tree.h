#ifndef TREE_H

#include <vector>
#include <queue>
#include <string>

using namespace std;

/*
   A visitor whose visit member function is called for each visited node
   during a tree traversal.
*/
class Visitor
{
public:   
   /**
      This member function is called for each visited node.
      @param data the data of the node
   */
   virtual void visit(string data);
};

class BreadthFirstIterator;

class Node
{
private:
   /**
      Computes the size of the subtree whose root is this node.
      @return the number of nodes in the subtree
   */
   int size() const;

   string data;
   vector<Node*> children;
friend class BreadthFirstIterator;
friend class Tree;
};

/*
   A tree in which each node has an arbitrary number of children.
*/
class Tree
{
public:
   /**
      Constructs an empty tree.
   */
   Tree();

   /**
      Constructs a tree with one node and no children.
      @param root_data the data for the root
   */
   Tree(string root_data);

   /**
      Adds a subtree as the last child of the root.
   */
   void add_subtree(const Tree& subtree);

   /**
      Computes the size of this tree.
      @return the number of nodes in the tree
   */
   int size() const;

   /**
      Traverses this tree in preorder.
      @param v the visitor to be invoked at each node
   */
   void preorder(Visitor& v) const;
   
   /**
      Traverses this tree in postorder.
      @param v the visitor to be invoked at each node
   */
   void postorder(Visitor& v) const;

   /**
      Traverses this tree in breadth first order.
      @param v the visitor to be invoked at each node
   */
   void breadth_first(Visitor& v) const;

   /**
      Yields an iterator for breadth-first traversal that points
      to the first element of this tree.
      @return the iterator
   */
   BreadthFirstIterator begin() const;
   
   /**
      Yields an iterator for breadth-first traversal that points
      past the last element of this tree.
      @return the iterator
   */
   BreadthFirstIterator end() const;

 private:   
   /**
      Traverses the tree with a given root in preorder.
      @param n the root of the tree
      @param v the visitor to be invoked at each node
   */
   void preorder(Node* n, Visitor& v) const;

   /**
      Traverses the tree with a given root in postorder.
      @param n the root of the tree
      @param v the visitor to be invoked at each node
   */
   void postorder(Node* n, Visitor& v) const;
   
   Node* root;
};

/**
   This iterator visits the nodes of a tree in 
   breadth-first order.
*/
class BreadthFirstIterator
{
 public:
   /**
      Constructs an iterator for a given tree.
      @param root the root of the tree
   */
   BreadthFirstIterator(Node* root);
   /**
      Gets the element to which this iterator points.
      @return the element
   */
   string get() const;
   /**
      Advances this iterator to the next position.
   */
   void next();
   bool equals(const BreadthFirstIterator& other) const;
   
private:
   queue<Node*> q;
};

#endif
