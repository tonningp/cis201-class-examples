#include "tree.h"

Tree::Tree()
{
   root = nullptr;
}

Tree::Tree(string root_data)
{
   root = new Node;
   root->data = root_data;
}

void Tree::add_subtree(const Tree& subtree)
{
   root->children.push_back(subtree.root);
}

int Tree::size() const
{
   if (root == nullptr) { return 0; }
   else { return root->size(); }
}

int Node::size() const
{
   int sum = 0;
   for (Node* child : children) { sum = sum + child->size(); }
   return 1 + sum;
}

