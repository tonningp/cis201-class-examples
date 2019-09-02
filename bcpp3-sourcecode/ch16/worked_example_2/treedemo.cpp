#include <algorithm>
#include <cmath>
#include <iostream>
#include "red_black_tree.h"

using namespace std;

/*
   This program tests the red-black tree class.
*/

/**
   Runs the simple test from the textbook.
*/
void test_from_book()
{
   RedBlackTree t;
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
   cout << "Expected: C E G H I J" << endl;   
}

/**
   Inserts all permutations of a string into a red-black tree and checks that 
   it contains the strings afterward.
   @param letters a sorted string of letters without repetition
   @return the number of passing tests
*/
int insertion_test(string letters)
{
   int count = 0;
   string s = letters;
   do
   {
      RedBlackTree t;
      for (int i = 0; i < s.length(); i++)
      {
         t.insert(s.substr(i, 1));
      }
      bool pass = true;
      for (int i = 0; i < s.length(); i++)
      {
         string e = s.substr(i, 1);
         if (t.count(e) == 0)
         {
            cout << e << " not inserted" << endl;
            pass = false;
         }
      }
      if (pass) 
      {
         count++;
      }
      else
      {
         cout << "Failing for letters " << letters << endl;
      }
   }
   while(next_permutation(s.begin(), s.end()));
   return count;
}

/**
   Counts the nodes in a binary tree.
   @param n the root of a binary tree
   @return the number of nodes in the tree
*/
int size(Node* n)
{
   if (n == nullptr) { return 0; }
   else { return 1 + size(n->left) + size(n->right); }
}

/**
   Computes the cost from a node to a root.
   @param n a node of a red-black tree
   @return the number of black nodes between n and the root
*/
int cost_to_root(Node* n)
{
   int c = 0;
   while (n != nullptr) { c = c + n->color; n = n->parent; }
   return c;
}

/**
   Copies all nodes of a red-black tree.
   @param n the root of a red-black tree
   @return the root node of a copy of the tree
*/
Node* copy(Node* n)
{
   if (n == nullptr) { return nullptr; }
   Node* new_node = new Node;
   new_node->set_left_child(copy(n->left));
   new_node->set_right_child(copy(n->right));
   new_node->data = n->data;
   new_node->color = n->color;
   return new_node;
}

/**
   Generates the mirror image of a red-black tree.
   @param n the root of the tree to reflect
   @return the root of the mirror image of the tree
*/
Node* mirror(Node* n)
{
   if (n == nullptr) { return nullptr; }
   Node* new_node = new Node;
   new_node->set_left_child(mirror(n->right));
   new_node->set_right_child(mirror(n->left));
   new_node->data = n->data;
   new_node->color = n->color;
   return new_node;
}

/**
   Makes a full tree of black nodes of a given depth.
   @param depth the desired depth
   @return the root node of a full black tree
*/
Node* full_tree(int depth)
{
   if (depth <= 0) { return nullptr; }
   Node* r = new Node;
   r->color = BLACK;
   r->set_left_child(full_tree(depth - 1));
   r->set_right_child(full_tree(depth - 1));
   return r;
}

/**
   Gets all nodes of a subtree and fills them into a vector.
   @param n the root of the subtree
   @param nodes the vector into which to place the nodes
*/
void get_nodes(Node* n, vector<Node*>& nodes)
{
   if (n == nullptr) { return; }
   get_nodes(n->left, nodes);
   nodes.push_back(n);
   get_nodes(n->right, nodes);
}

/**
   Prints a detailed view of a binary tree.
   @param n the root of the tree to print
   @param level the indentation level for the root
*/   
void print_detailed(Node* n, int level)
{
   if (n == nullptr) { return; }
   print_detailed(n->left, level + 1);
   for (int i = 0; i < level; i++) { cout << "  "; }
   cout << n->data << " " << n->color << endl;
   print_detailed(n->right, level + 1);
}

/**
   Populates a tree with the values A, B, C, ... .
   @param t a red-black tree
   @return the number of nodes in t
*/
int populate(RedBlackTree t)
{
   vector<Node*> nodes;
   get_nodes(t.root, nodes);
   for (int i = 0; i < nodes.size(); i++)
   {
      string d = "A";
      d[0] = d[0] + i;
      nodes[i]->data = d;
   }
   return nodes.size();
}   
   
/**
   Checks that the tree with the given node is a red-black tree
   and prints an error message if a structural error is found.
   @param n the root of the subtree to check
   @param is_root true if this is the root of the tree
   @param report_errors whether error messages should be printed
   @return the black depth of this subtree, or -1 if this is not a 
   valid red-black tree
*/
int check_red_black(Node* n, bool is_root, bool report_errors)
{
   if (n == nullptr) { return 0; }
   int nleft = check_red_black(n->left, false, report_errors);
   int nright = check_red_black(n->right, false, report_errors);
   if (nleft == -1 || nright == -1) return -1;
   if (nleft != nright) 
   {
      if (report_errors)
      {
         cout << "Left and right children of " << n->data 
            << " have different black depths" << endl;
      }
      return -1;
   }
   if (n->parent == nullptr)
   {
      if (!is_root) 
      {
         if (report_errors)
         {
            cout << n->data << " is not root and has no parent" << endl;
         }
         return -1;
      }
      if (n->color != BLACK) 
      {
         if (report_errors)
         {
            cout << "Root " << n->data << " is not black";
         }
         return -1;
      }
   }
   else
   {
      if (is_root) 
      {
         if (report_errors)
         {
            cout << n->data << " is root and has a parent" << endl;
         }
         return -1;
      }
      if (n->color == RED && n->parent->color == RED) 
      {
         if (report_errors)
         {
            cout << "Parent of red " << n->data << " is red" << endl;
         }
         return -1;
      }
   }
   if (n->left != nullptr && n->left->parent != n) 
   {
      if (report_errors)
      {
         cout << "Left child of " << n->data
            << " has bad parent link" << endl;
      }
      return -1;
   }
   if (n->right != nullptr && n->right->parent != n) 
   {
      if (report_errors)
      {         
         cout << "Right child of " << n->data
            << " has bad parent link" << endl;
      }
      return -1;
   }
   if (n->color != RED && n->color != BLACK) 
   {
      if (report_errors)
      {         
         cout << n->data + " has color " << n->color;
      }
      return -1;
   }
   return n->color + nleft;
}

/**
   Checks whether a red-black tree is valid and reports an error if not.
   @param t the tree to test
   @param report_errors whether error messages should be printed
   @return true if the tree passes, false if not
*/
bool check_red_black(RedBlackTree& t, bool report_errors)
{
   int result = check_red_black(t.root, true, report_errors);
   if (result == -1) { return false; }     
   
   // Check that it's a BST
   vector<Node*> nodes;
   get_nodes(t.root, nodes);
   for (int i = 0; i < nodes.size() - 1; i++)
   {
      if (nodes[i]->data > nodes[i + 1]->data > 0)
      {
         if (report_errors)
         {
            cout << nodes[i]->data << " is larger than " <<
               nodes[i + 1]->data << endl;
         }
         return false;
      }
   }
   return true;
}

/**
   Tests removal, given a template for a tree with a black node that
   is to be deleted. All other nodes should be given all possible combinations 
   of red and black.
   @param t the template for the test cases
   @return the number of passing tests
*/
int removal_test(const RedBlackTree& t)
{
   int count = 0;
   for (int m = 0; m <= 1; m++)
   {
      int nodes_to_color = size(t.root) - 2;
        // We don't recolor the root or to_delete
      for (int k = 0; k < pow(2, nodes_to_color); k++)
      {
         RedBlackTree rb;
         if (m == 0) { rb.root = copy(t.root); }
         else { rb.root = mirror(t.root); }
         vector<Node*> nodes;
         get_nodes(rb.root, nodes);
         Node* to_delete = nullptr;

         // Color with the bit pattern of k
         int bits = k;
         for (Node* n : nodes)
         {
            if (n == rb.root)
            {
               n->color = BLACK;
            }
            else if (n->color == BLACK) 
            { 
               to_delete = n; 
            }
            else 
            {
               n->color = bits % 2;
               bits = bits / 2;
            }
         }
	
         // Add children to make equal costs to nullptr
         int target_cost = cost_to_root(to_delete);
         for (Node* n : nodes) 
         {
            int cost = target_cost - cost_to_root(n);
            if (n->left == nullptr)
            {
               n->set_left_child(full_tree(cost));
            }
            if (n->right == nullptr)
            {
               n->set_right_child(full_tree(cost));
            }
         }
		   
         int filled_size = populate(rb);

         if (check_red_black(rb, false)) // Found a valid tree
         {            
            string d = to_delete->data;
            rb.erase(d);
            bool pass = check_red_black(rb, true);
            for (int j = 0; j < filled_size; j++)
            {
               string s = "A";
               s[0] = s[0] + j;
               if (rb.count(s) == 0 && d != s)
               {
                  cout << s + " deleted" << endl;
                  pass = false;
               }
            }
            if (rb.count(d) > 0)
            {
               cout << d + " not deleted" << endl;
               pass = false;
            }
            if (pass)
            {
               count++;
            }
            else
            {
               cout << "Failing tree: " << endl;
               print_detailed(rb.root, 0);
            }
         }
      }
   }
   return count;
}

/**
   Makes a template for testing removal.
   The node to be removed is black.
   @return a partially complete red-black tree for the test. 
*/
RedBlackTree removal_test_template() 
{
   RedBlackTree result; 
      
   /*
                            n7
                           /  \
                          n1   n8
                         /  \
                       n0    n3
                            /  \
                           n2*  n5
                                /\
                              n4  n6
   */

   Node* n[9];
   for (int i = 0; i < 9; i++) { n[i] = new Node; }
   result.root = n[7];
   n[7]->set_left_child(n[1]);
   n[7]->set_right_child(n[8]);
   n[1]->set_left_child(n[0]);
   n[1]->set_right_child(n[3]);
   n[3]->set_left_child(n[2]);
   n[3]->set_right_child(n[5]);
   n[5]->set_left_child(n[4]);
   n[5]->set_right_child(n[6]);     
   n[2]->color = BLACK;   
   return result;
}  

int main()
{
   test_from_book();
   int passing = insertion_test("ABCDEFGHIJ");
   cout << passing << " insertion tests passed." << endl;
   passing = removal_test(removal_test_template());
   cout << passing << " removal tests passed." << endl;
   return 0;
}
