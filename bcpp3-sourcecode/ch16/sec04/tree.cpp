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

void Visitor::visit(string data) {}

BreadthFirstIterator Tree::begin() const
{
   return BreadthFirstIterator(root);
}

BreadthFirstIterator Tree::end() const
{
   return BreadthFirstIterator(nullptr);
}

BreadthFirstIterator::BreadthFirstIterator(Node* root)
{
   if (root != nullptr) { q.push(root); }
}

string BreadthFirstIterator::get() const
{
   return q.front()->data;
}

void BreadthFirstIterator::next()
{
   Node* n = q.front();
   q.pop();
   for (Node* c : n->children) { q.push(c); }
}

bool BreadthFirstIterator::equals(
   const BreadthFirstIterator& other) const
{
   return q.size() == 0 && other.q.size() == 0
      || q.size() > 0 && other.q.size() > 0
         && q.front() == other.q.front();
}

void Tree::preorder(Visitor &v) const { preorder(root, v); }
void Tree::postorder(Visitor &v) const { postorder(root, v); }
void Tree::breadth_first(Visitor& v) const
{
   if (root == nullptr) { return; }
   queue<Node*> q;
   q.push(root);
   while (q.size() > 0)
   {
      Node* n = q.front();
      v.visit(n->data);
      for (Node* c : n->children) { q.push(c); }
   }
}

void Tree::preorder(Node* n, Visitor& v) const
{
   if (n == nullptr) { return; }
   v.visit(n->data);
   for (Node* c : n->children) { preorder(c, v); }
}

void Tree::postorder(Node* n, Visitor &v) const
{
   if (n == nullptr) { return; }
   for (Node* c : n->children) { postorder(c, v); }
   v.visit(n->data);
}

   

   


