#include <iostream>
#include <string>

using namespace std;

class TreeNode
{
public:
   void insert_node(TreeNode* new_node);
   void print_nodes() const;
   bool find(string value) const;
private:
   string data;
   TreeNode* left;
   TreeNode* right;
friend class BinarySearchTree;
};

class BinarySearchTree
{
public:
   BinarySearchTree();
   void insert(string data);
   void erase(string data);
   int count(string data) const;
   void print() const;
private:
   TreeNode* root;
};

BinarySearchTree::BinarySearchTree()
{  
   root = NULL;
}

void BinarySearchTree::print() const
{  
   if (root != NULL)
      root->print_nodes();
}

void BinarySearchTree::insert(string data)
{  
   TreeNode* new_node = new TreeNode;
   new_node->data = data;
   new_node->left = NULL;
   new_node->right = NULL;
   if (root == NULL) root = new_node;
   else root->insert_node(new_node);
}

void TreeNode::insert_node(TreeNode* new_node)
{  
   if (new_node->data < data)
   {  
      if (left == NULL) left = new_node;
      else left->insert_node(new_node);
   }
   else if (data < new_node->data)
   {  
      if (right == NULL) right = new_node;
      else right->insert_node(new_node);
   }
}

int BinarySearchTree::count(string data) const
{
   if (root == NULL) return 0;
   else if (root->find(data)) return 1;
   else return 0;
}

void BinarySearchTree::erase(string data)
{
   // Find node to be removed

   TreeNode* to_be_removed = root;
   TreeNode* parent = NULL;
   bool found = false;
   while (!found && to_be_removed != NULL)
   {
      if (to_be_removed->data < data)
      {
         parent = to_be_removed;
         to_be_removed = to_be_removed->right;
      }
      else if (data < to_be_removed->data)
      {
         parent = to_be_removed;
         to_be_removed = to_be_removed->left;
      }
      else found = true;
   }

   if (!found) return;

   // to_be_removed contains data

   // If one of the children is empty, use the other

   if (to_be_removed->left == NULL || to_be_removed->right == NULL)
   {
      TreeNode* new_child;
      if (to_be_removed->left == NULL) 
         new_child = to_be_removed->right;
      else 
         new_child = to_be_removed->left;
       if (parent == NULL) // Found in root
         root = new_child;
      else if (parent->left == to_be_removed)
         parent->left = new_child;
      else 
         parent->right = new_child;
      return;
   }
      
   // Neither subtree is empty

   // Find smallest element of the right subtree

   TreeNode* smallest_parent = to_be_removed;
   TreeNode* smallest = to_be_removed->right;
   while (smallest->left != NULL)
   {
      smallest_parent = smallest;
      smallest = smallest->left;
   }

   // smallest contains smallest child in right subtree
       
   // Move contents, unlink child
   to_be_removed->data = smallest->data;
   if (smallest_parent == to_be_removed) 
      smallest_parent->right = smallest->right; 
   else 
      smallest_parent->left = smallest->right; 
}
 
bool TreeNode::find(string value) const
{
   if (value < data)
   {
      if (left == NULL) return false;
      else return left->find(value);
   }
   else if (data < value)
   {
      if (right == NULL) return false;
      else return right->find(value);
   }
   else 
      return true;
}

void TreeNode::print_nodes() const
{  
   if (left != NULL)
      left->print_nodes();
   cout << data << "\n";
   if (right != NULL)
      right->print_nodes();
}

int main()
{  
   BinarySearchTree t;
   t.insert("D");
   t.insert("B");
   t.insert("A");
   t.insert("C");
   t.insert("F");
   t.insert("E");
   t.insert("I");
   t.insert("G");
   t.insert("H");
   t.insert("J");
   t.erase("A"); // Removing leaf
   t.erase("B"); // Removing element with one child
   t.erase("F"); // Removing element with two children
   t.erase("D"); // Removing root
   t.print();
   cout << t.count("E") << "\n";
   cout << t.count("F") << "\n";
   return 0;
}
