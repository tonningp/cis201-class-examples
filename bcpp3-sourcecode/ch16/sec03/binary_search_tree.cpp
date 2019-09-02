#include <iostream>
#include "binary_search_tree.h"

using namespace std;

BinarySearchTree::BinarySearchTree()
{  
   root = nullptr;
}
   
void BinarySearchTree::insert(string element) 
{  
   Node* new_node = new Node;
   new_node->data = element;
   new_node->left = nullptr;
   new_node->right = nullptr;
   if (root == nullptr) { root = new_node; }
   else { add_node(root, new_node); }
}

int BinarySearchTree::count(string element) const
{
   Node* current = root;
   while (current != nullptr)
   {
      if (element < current->data)
      {
         current = current->left;
      }
      else if (element > current->data)
      {
         current = current->right;
      }
      else return 1;      
   }
   return 0;
}
   
void BinarySearchTree::erase(string element)
{
   // Find node to be removed
   
   Node* to_be_removed = root;
   Node* parent = nullptr;
   bool found = false;
   while (!found && to_be_removed != nullptr)
   {
      if (element == to_be_removed->data)
      {
         found = true;
      }
      else
      {
         parent = to_be_removed;
         if (element < to_be_removed->data)
         {
            to_be_removed = to_be_removed->left;
         }
         else
         {
            to_be_removed = to_be_removed->right;
         }
      }      
   }

   if (!found) { return; }

   // to_be_removed contains element

   // If one of the children is empty, use the other

   if (to_be_removed->left == nullptr || to_be_removed->right == nullptr)
   {
      Node* new_child;
      if (to_be_removed->left == nullptr) 
      {
         new_child = to_be_removed->right;
      }
      else 
      {
         new_child = to_be_removed->left;
      }

      if (parent == nullptr) // Found in root
      {
         root = new_child;
      }
      else if (parent->left == to_be_removed)
      {
         parent->left = new_child;
      }
      else 
      {
         parent->right = new_child;
      }
      return;
   }
      
   // Neither subtree is empty

   // Find smallest element of the right subtree

   Node* smallest_parent = to_be_removed;
   Node* smallest = to_be_removed->right;
   while (smallest->left != nullptr)
   {
      smallest_parent = smallest;
      smallest = smallest->left;
   }

   // smallest contains smallest child in right subtree
         
   // Move contents, unlink child

   to_be_removed->data = smallest->data;
   if (smallest_parent == to_be_removed) 
   {
      smallest_parent->right = smallest->right; 
   }
   else 
   {
      smallest_parent->left = smallest->right; 
   }
}
   
void BinarySearchTree::print() const
{  
   print(root);
   cout << endl;
}  

void BinarySearchTree::print(Node* parent) const
{  
   if (parent == nullptr) { return; }
   print(parent->left);
   cout << parent->data << " ";
   print(parent->right);
}

void BinarySearchTree::add_node(Node* parent, Node* new_node) const
{  
   if (new_node->data < parent->data)
   {  
      if (parent->left == nullptr) { parent->left = new_node; }
      else { add_node(parent->left, new_node); }
   }
   else if (new_node->data > parent->data)
   {  
      if (parent->right == nullptr) { parent->right = new_node; }
      else { add_node(parent->right, new_node); }
   }
}



